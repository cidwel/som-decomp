.setcpu "65816"
.segment "CODE"
.org $F133
map_control_0ff133:
    .byte $C4 ; same-value copy count/distance
