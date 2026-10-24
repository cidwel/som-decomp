.setcpu "65816"
.segment "CODE"
.org $CADE
map_control_0dcade:
    .byte $C7 ; same-value copy count/distance
