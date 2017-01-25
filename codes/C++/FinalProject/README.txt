{\rtf1\ansi\ansicpg1252\cocoartf1504
{\fonttbl\f0\fswiss\fcharset0 Helvetica;\f1\fnil\fcharset0 Menlo-Bold;\f2\fnil\fcharset0 Menlo-Regular;
}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;\red170\green13\blue145;}
{\*\expandedcolortbl;\csgray\c100000;\csgenericrgb\c0\c0\c0;\csgenericrgb\c66500\c5200\c56900;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 \
1. How to play the game:\
\
You have to get 5 pieces connected to win the game, see option 2 in main menu. Below is an example of the computer (o) wins the game.\
\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f1\b\fs22 \cf2 \CocoaLigature0 --------------------------------\
      Welcome to Gomoku Game    \
--------------------------------\
         Main Menu:             \
         1. Start Game          \
         2. Help                \
         q. Exit                \
--------------------------------\
1\
Game start, your piece is X\
0 1 2 3 4 5 6 7 8 9\
1                   \
2                   \
3                   \
4                   \
5                   \
6                   \
7                   \
8                   \
9                   \
Enter X coordinate\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f2\b0 \cf2 5\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f1\b \cf2 Enter Y coordinate\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f2\b0 \cf2 6\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f1\b \cf2 X: 5 Y: 6\
0 1 2 3 4 5 6 7 8 9\
1                   \
2                   \
3                   \
4                   \
5       O           \
6         X         \
7                   \
8                   \
9                   \
Enter X coordinate\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f2\b0 \cf2 7\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f1\b \cf2 Enter Y coordinate\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f2\b0 \cf2 7\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f1\b \cf2 X: 7 Y: 7\
0 1 2 3 4 5 6 7 8 9\
1                   \
2                   \
3                   \
4                   \
5       O O         \
6         X         \
7             X     \
8                   \
9                   \
Enter X coordinate\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f2\b0 \cf2 9\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f1\b \cf2 Enter Y coordinate\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f2\b0 \cf2 9\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f1\b \cf2 X: 9 Y: 9\
0 1 2 3 4 5 6 7 8 9\
1                   \
2                   \
3                   \
4                   \
5       O O O       \
6         X         \
7             X     \
8                   \
9                 X \
Enter X coordinate\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f2\b0 \cf2 3\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f1\b \cf2 Enter Y coordinate\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f2\b0 \cf2 3\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f1\b \cf2 X: 3 Y: 3\
0 1 2 3 4 5 6 7 8 9\
1                   \
2                   \
3     X             \
4                   \
5     O O O O       \
6         X         \
7             X     \
8                   \
9                 X \
Enter X coordinate\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f2\b0 \cf2 2\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f1\b \cf2 Enter Y coordinate\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f2\b0 \cf2 2\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f1\b \cf2 X: 2 Y: 2\
0 1 2 3 4 5 6 7 8 9\
1                   \
2   X               \
3     X             \
4                   \
5   O O O O O       \
6         X         \
7             X     \
8                   \
9                 X \
Computer wins!\
\pard\tx543\pardeftab543\pardirnatural\partightenfactor0

\f0\b0\fs24 \cf0 \CocoaLigature1 \
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0
\cf0 \
\
\
2. To quickly find the code requirements:\
\
STL structure: Array.h \'93
\f2\fs22 \cf2 \CocoaLigature0 vector< vector<\cf3 int\cf2 > > adData\'94\
Inheritance: WIN.h\
Exception class: exception.h\
}