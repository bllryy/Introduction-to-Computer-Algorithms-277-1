#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    int index;
    int prev_hash;
    int hash;
    char data[32];
    struct Block *next;
} Block;

typedef struct Blockchain {
    Block *head;
    Block *tail;
    int length;
} Blockchain;

typedef struct Peer {
    int id;
    Blockchain chain;
    struct Peer *next;
} Peer;



int hash_string(const char *s)
{
    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        sum += (unsigned char)s[i];
    }
    return sum;
}

int compute_hash(int index, int prev_hash, const char *data)
{
    return index + prev_hash + hash_string(data);
}


void init_blockchain(Blockchain *bc)
{
	bc->head = (Block *)malloc(sizeof(Block));
	bc->head->index = 0;
	strcpy(bc->head->data, "GENESIS");
	bc->head->prev_hash = 0;
	bc->head->hash = compute_hash(bc->head->index, bc->head->prev_hash, bc->head->data);
	bc->head->next = NULL;

	bc->tail = bc->head;
	bc->length = 1;
}

int add_block(Blockchain *bc, const char *data)
{
	Block* new_block = (Block*)malloc(sizeof(Block));
	new_block->index = bc->tail->index + 1;
	new_block->prev_hash = bc->tail->hash;
	strcpy(new_block->data, data);
	new_block->hash = compute_hash(new_block->index, new_block->prev_hash,new_block->data);
	new_block->next = NULL;

	bc->tail->next = new_block;
	bc->tail = new_block;
	bc->length++;
	return 0;
}

void print_chain(const Blockchain *bc) {
Block *current = bc->head;
  while (current != NULL) {
      printf(" Block: %d\n", current->index);
      printf("  Index: %d\n", current->index);
      printf("  Hash: %d\n", current->hash);
      printf("  Data: %s\n", current->data);
      current = current->next; // next block
  }
}

// CHECK work
int is_valid_chain(const Blockchain *bc)
{
    if (bc->head->hash != compute_hash(bc->head->index, bc->head->prev_hash, bc->head->data)) return 0; 

    Block *current = bc->head;
    while (current != NULL) {
        if (current->index != (current->prev_hash == 0 ? 0 : current->index - 1)) {
            return 0;
        }

        int expected_hash = compute_hash(current->index, current->prev_hash, current->data);
        if (current->hash != expected_hash) return 0; 

        current = current->next; 
    }
    return 1; 

}

void free_blockchain(Blockchain *bc) {
  Block *current = bc->head;
  Block *next_node;

  while (current != NULL) {
    next_node = current->next;

    free(current);
    current = next_node;
  }
}

Peer *add_peer(Peer *net, int id) 
{
	Peer *new_peer = (Peer *)malloc(sizeof(Peer));

	new_peer->id = id;
	init_blockchain(&new_peer->chain);
	new_peer->next = net;
	return new_peer;
}

Peer* find_peer(Peer *net, int id) 
{
  while (net != NULL)
{
    if (net->id == id)
{
        return net;
    }
    net = net->next;
  }
  return NULL;
}

//TODO
void print_network(const Peer *net) 
{
const Peer *current = net;
    while (current != NULL) 
{
        printf("Peer ID: %d, Length: %d, Validity: %s\n",
               current->id, current->chain.length, is_valid_chain(&current->chain) ? "Valid" : "Invalid");
        print_chain(&current->chain); // Print chain details
        current = current->next; // Move to the next peer
}
}

void broadcast(Peer *net, const char *data) 
{
	while(net != NULL)
	{
		if(is_valid_chain(&net->chain))
		{
			add_block(&net->chain, data);
		}
		net = net->next;
	}
}

int tamper_peer(Peer *net, int peer_id, int block_index, const char *new_data) 
{
	Peer *peer = find_peer(net, peer_id);
		Block *current = peer->chain.head;
    		for (int i = 0; i < block_index; i++) 
		{
        		if (current == NULL) return -1; 
        		current = current->next; 
    		}
    	strcpy(current->data, new_data); // 
    	return 0;
}

Peer* consensus_winner(Peer *net) 
{
Peer *winner = NULL;
int max_length = 0;

	while (net != NULL) 
	{
			if (is_valid_chain(&net->chain) && net->chain.length > max_length) 
		{
			max_length = net->chain.length;
			winner = net; 
        	}
	net = net->next; 
    	}
	return winner; 
}


void apply_consensus(Peer *net) 
{
	Peer *winner = consensus_winner(net);
	
	while(net != NULL)
	{
		free_blockchain(&net->chain);
		net->chain = winner->chain;
		net=net->next;
	}
}

void free_network(Peer *net) 
{
	Peer *current = net;
	while(current != NULL)
	{
		Peer *next_peer = current->next;
		free_blockchain(&current->chain);
		free(current);
		current = next_peer;
	}
}


int main(void) {
    Peer *net = NULL;


    net = add_peer(net, 1);
    net = add_peer(net, 2);
    net = add_peer(net, 3);

    printf("Initial network:\n");
    print_network(net);


    broadcast(net, "A");
    broadcast(net, "B");
    broadcast(net, "C");

    printf("\nAfter broadcasting A, B, C:\n");
    print_network(net);


    printf("\nTampering peer 2 at block index 2...\n");
    tamper_peer(net, 2, 2, "HACKED");

    printf("\nAfter tamper:\n");
    print_network(net);


    broadcast(net, "D");

    printf("\nAfter broadcasting D (invalid peers skipped):\n");
    print_network(net);


    Peer *win = consensus_winner(net);
    if (win) {
        printf("\nConsensus winner is Peer %d (length=%d)\n", win->id, win->chain.length);
    } else {
        printf("\nNo valid chains found.\n");
    }

    printf("\nApplying consensus (sync all peers to winner)...\n");
    apply_consensus(net);

    printf("\nAfter apply_consensus:\n");
    print_network(net);

    free_network(net);
    return 0;
}
