.setcpu "65816"
.segment "CODE"
.org $F7EF
map_control_0ff7ef:
    .byte $C2 ; same-value copy count/distance
