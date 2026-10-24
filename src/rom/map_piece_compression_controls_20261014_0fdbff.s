.setcpu "65816"
.segment "CODE"
.org $DBFF
map_control_0fdbff:
    .byte $C6 ; same-value copy count/distance
