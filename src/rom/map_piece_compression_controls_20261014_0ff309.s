.setcpu "65816"
.segment "CODE"
.org $F309
map_control_0ff309:
    .byte $C4 ; same-value copy count/distance
