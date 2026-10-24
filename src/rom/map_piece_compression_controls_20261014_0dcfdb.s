.setcpu "65816"
.segment "CODE"
.org $CFDB
map_control_0dcfdb:
    .byte $C2 ; same-value copy count/distance
