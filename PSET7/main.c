#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>

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
  Block *genesis = (Block *)malloc(sizeof(Block));
  // always at 0, always GENESIS, prev hash 0
  genesis->index = 0;
  strcpy(genesis->data, "GENESIS");
  genesis->prev_hash = 0;
  genesis->next = NULL;
}

int add_block(Blockchain *bc, const char *data)
{
  // malloc new block
  Block* new_block = (Block*)malloc(sizeof(Block));
  new_block->data = data;

  // set last hash
  if (bc->tail != NULL)
  {
    strcpy(new_block->prev_hash, bc->tail->hash);
    bc->head = new_block;
  } else {
    strcpy(new_block->prev_hash, "0");
    bc->head = new_block;
  }

  compute_hash(new_block);

  return 0;

}

void print_chain(const Blockchain *bc) {
  struct Block* current = chain;
  int count = 0;

  while (current != NULL) {
      printf(" Block: %d\n", count++);
      printf("  Index: %d\n", current->index);
      printf("  Hash: %s\n", current->hash);
      printf("  Data: %s\n", current->data);
      current = current->next; // next block
  }
}

int is_valid_chain(const Blockchain *bc)
{

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

Peer *add_peer(Peer *net, int id) {

}

//TODO
Peer* find_peer(Peer *net, int id) {
  i = 0;
  while (i < peer_count) {
    if (peers[i].id == search_id) {
        return &peers[i];
    }
    i++;
  }
  return NULL;
}

//TODO
void print_network(const Peer *net) {
  for(i = 0; i < peer_count; i++) {
    printf("Peer ID: %d, Length: %d, Validity: %s\n",
           peers[i].id, peers[i].length, peers[i].is_valid ? "Valid" : "Invalid");
    // if exist print
    if (peers[i].blockchain != NULL) {
        printf("Details for peer id %d:\n", peers[i].id);
        print_chain(peers[i].blockchain);
    }
  }
}

void broadcast(Peer *net, const char *data) {

}

int tamper_peer(Peer *net, int peer_id, int block_index, const char *new_data) {

}

Peer* consensus_winner(Peer *net) {

}


void apply_consensus(Peer *net) {

}

void free_network(Peer *net) {

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
