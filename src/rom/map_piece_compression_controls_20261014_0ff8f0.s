.setcpu "65816"
.segment "CODE"
.org $F8F0
map_control_0ff8f0:
    .byte $D2 ; same-value copy count/distance
