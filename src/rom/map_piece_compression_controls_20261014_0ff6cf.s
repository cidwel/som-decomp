.setcpu "65816"
.segment "CODE"
.org $F6CF
map_control_0ff6cf:
    .byte $C3 ; same-value copy count/distance
