.setcpu "65816"
.segment "CODE"
.org $F5FF
map_control_0ff5ff:
    .byte $C3 ; same-value copy count/distance
