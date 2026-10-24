.setcpu "65816"
.segment "CODE"
.org $DADB
map_control_0ddadb:
    .byte $C7 ; same-value copy count/distance
