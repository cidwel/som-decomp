.setcpu "65816"
.segment "CODE"
.org $F63F
map_control_0ff63f:
    .byte $C5 ; same-value copy count/distance
