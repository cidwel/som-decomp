.setcpu "65816"
.segment "CODE"
.org $F8AB
map_control_0ff8ab:
    .byte $C1 ; same-value copy count/distance
