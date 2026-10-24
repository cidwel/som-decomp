.setcpu "65816"
.segment "CODE"
.org $DBBC
map_control_0fdbbc:
    .byte $C2 ; same-value copy count/distance
