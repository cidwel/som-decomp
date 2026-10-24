.setcpu "65816"
.segment "CODE"
.org $F0F7
map_control_0ff0f7:
    .byte $C4 ; same-value copy count/distance
