#cancel jobs on cluster

use warnings;

open C, ">cancel.sh";
for $i(1004852..1005621){
    print C "qdel $i\n";

}
