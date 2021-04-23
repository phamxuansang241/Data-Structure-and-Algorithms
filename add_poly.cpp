#include<bits/stdc++.h>

using namespace std;

struct node {
    int coeff;
    int power;
    node* next;
};

void append(node** temp, int c, int p) {
    node* new_node = new node();
    new_node->coeff = c;
    new_node->power = p;
    new_node->next = NULL;

    if(*temp == NULL) {
        *temp = new_node;
        return;
    }

    node* cur_node = *temp;
    while(cur_node->next != NULL)
        cur_node = cur_node->next;
    cur_node->next = new_node;
}

void show(node* temp) {
    while(temp != NULL) {
        cout << temp->coeff << "x^" << temp->power;

        if(temp->next != NULL)
            cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}


void polyadd(node* poly_fi, node* poly_se, node* poly) {
    while(poly_fi && poly_se) {

        if(poly_fi->power > poly_se->power) {
            poly->coeff = poly_fi->coeff;
            poly->power = poly_fi->power;
            poly_fi = poly_fi->next;
        }
        else if(poly_fi->power < poly_se->power) {
            poly->coeff = poly_se->coeff;
            poly->power = poly_se->power;
            poly_se = poly_se->next;
        }
        else {
            poly->coeff = poly_fi->coeff + poly_se->coeff;
            poly->power = poly_fi->power;
            poly_fi = poly_fi->next;
            poly_se = poly_se->next;
        }

        if(poly_fi && poly_se) {
            poly->next = new node();
            poly = poly->next;
            poly->next = NULL;
        }
    }

    while (poly_fi || poly_se) {
        poly->next = new node();
        poly = poly->next;
        poly->next = NULL;

        if (poly_fi) {
            poly->coeff = poly_fi->coeff;
            poly->power = poly_fi->power;
            poly_fi = poly_fi->next;
        }
        if (poly_se) {
            poly->coeff = poly_se->coeff;
            poly->power = poly_se->power;
            poly_se = poly_se->next;
        }
    }
}

int main() {
    node* poly_A = NULL;
    append(&poly_A, 5, 4);
    append(&poly_A, 4, 3);
    append(&poly_A, 3, 2);
  //  append(&poly_A, 2, 0);

    cout << "Da thuc A: " << endl;
    show(poly_A);

    node* poly_B = NULL;
    append(&poly_B, 10, 3);
    append(&poly_B, 2, 2);
    append(&poly_B, -4, 1);
    append(&poly_B, -12, 0);

    cout << "Da thuc B: " << endl;
    show(poly_B);

    node* poly = NULL;
    poly = new node();

    polyadd(poly_A, poly_B, poly);

    cout << "Tong hai da thuc: " << endl;
    show(poly);
}
