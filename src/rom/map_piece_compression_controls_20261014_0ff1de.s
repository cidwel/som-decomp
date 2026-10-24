.setcpu "65816"
.segment "CODE"
.org $F1DE
map_control_0ff1de:
    .byte $C4 ; same-value copy count/distance
