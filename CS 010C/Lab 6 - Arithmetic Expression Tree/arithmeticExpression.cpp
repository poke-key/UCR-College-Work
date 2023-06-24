#include "arithmeticExpression.h"

/* 
   Initializes an empty tree and sets the infixExpression
   to the value of parameter passed in. 
*/
arithmeticExpression::arithmeticExpression(const string &expr) {
    infixExpression = expr ;
    root = nullptr ;
}

/* destructor, cleanup the tree of all teh nodes*/
arithmeticExpression::~arithmeticExpression() {
    cleanup(root) ;    // call to delete nodes recursively
}

/* cleanup tree helper function to delete all nodes */
void arithmeticExpression::cleanup(TreeNode *tn) {
    if ( !tn)                   // exit confdition
        return ;

    cleanup(tn->left) ;
    cleanup(tn->right) ;
    delete tn ;
}

/* Converts the infixExpression to its equivalent postfix string
   and then generates the tree and assigns the root node to the 
   root data field. The key for the first node is 'a', 'b' for the second node and so on. 
   a, b,c ,c d
*/
void arithmeticExpression::buildTree() {
    string postfixExpression = infix_to_postfix() ;
    stack <TreeNode *> tempStack;

    for ( unsigned i=0; i< postfixExpression.size(); i++) {
        TreeNode* tn = new TreeNode(postfixExpression.at(i), 'a' + i); //key a, b, c and so on
        if ( !priority(postfixExpression.at(i))) {                     // not an operator
            tempStack.push(tn);                                         // push on stack
        }
        else {                                          // for operators priority > 0
            tn->right = tempStack.top();
            tempStack.pop();
            tn->left = tempStack.top();
            tempStack.pop();
            tempStack.push(tn);
            root = tn;            
       }
    }
}

void arithmeticExpression::infix() {
    infix(root);                        // call the recursive helper
}

void arithmeticExpression::prefix() {
    prefix(root);                       // call the recursive helper
}

void arithmeticExpression::postfix() {
    postfix(root);                      // call the recursive helper
}

/****************************************************************** 
 * function return priority based on the character in the expression
 ***************************************************************/
int arithmeticExpression::priority(char op) {
    int priority = 0;           // start with zero
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}
/****************************************************************** 
 * Helper function that returns the postfix notation equivalent
 * to the given infix expression 
*******************************************************************/
string arithmeticExpression::infix_to_postfix() {
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

/****************************************************************** 
Helper function that outputs the infix notation of the arithmetic expression tree
 by performing the inorder traversal of the tree.
 An opening and closing parenthesis must be added at the 
 beginning and ending of each expression. 
*******************************************************************/
void arithmeticExpression::infix(TreeNode *tn) {
    if ( !tn )                  // exit condition
        return ;

    if (priority(tn->data)) {       // handle brackets in infix 
		cout << "(";
		infix(tn->left);
		cout << tn->data;
		infix(tn->right);
		cout << ")";
	}
	else {        
        infix(tn->left) ;
        cout << tn->data ;
        infix(tn->right) ;
    }

}

/****************************************************************** 
 * Helper function that outputs the perfix notation of the arithmetic 
 * expression tree by performing the inorder traversal of the tree.
 * An opening and closing parenthesis must be added at the beginning 
 * and ending of each expression. 
*******************************************************************/
void arithmeticExpression::prefix(TreeNode *tn) {
    if ( !tn )              // exit condition
        return ;
    
    cout << tn->data ;
    prefix(tn->left) ;
    prefix(tn->right) ;
}
/****************************************************************** 
 * Helper function that outputs the postfix notation of the arithmetic 
 * expression tree by performing the inorder traversal of the tree.
 * An opening and closing parenthesis must be added at the beginning 
 * and ending of each expression. 
*******************************************************************/
void arithmeticExpression::postfix(TreeNode *tn) {
    if ( !tn )              // exit condition
        return ;

    postfix(tn->left) ;
    postfix(tn->right) ;
    cout << tn->data ;
}

void arithmeticExpression::visualizeTree(const string &outputFilename) {
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

 void arithmeticExpression::visualizeTree(ofstream &, TreeNode *){

 }

