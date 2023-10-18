#!/usr/bin/awk -f
BEGIN{
        print "\tWord Count\n--------------------------";
        total=0;
}

# check lines for #
!/#/{
# for loop incrementing total and dictionary
        for(i=1;i<=NF;i++){
                a[$i]++;
                total++;
        }
}

END {
        for(k in a){
# entries with 2 or more
                if(length(k) > 4 && a[k] > 2){
                        printf "%15s %s\n" ,k ,a[k];
                }
        }
        print "--------------------------";
        print "Number of Words : "total;
}
