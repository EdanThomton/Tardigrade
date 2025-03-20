/**
 * Comment placeholder tokens
 * 
 * @author Edan Thomton
 * @date 3/19/25
 */

#pragma once
#include "../token.cpp"

class CommentStart: public Token {
    public:
        CommentStart(): Token("CommentStart", "CommentStart"){}
};
class CommentEnd: public Token {
    public:
        CommentEnd(): Token("CommentEnd", "CommentEnd"){}
};
class SingleLineCommentStart: public Token {
    public:
        SingleLineCommentStart(): Token("SingleLineCommentStart", "SingleLineCommentStart"){}
};
class SingleLineCommentEnd: public Token {
    public:
        SingleLineCommentEnd(): Token("SingleLineCommentEnd", "SingleLineCommentEnd"){}
};