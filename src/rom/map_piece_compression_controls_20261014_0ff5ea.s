.setcpu "65816"
.segment "CODE"
.org $F5EA
map_control_0ff5ea:
    .byte $C3 ; same-value copy count/distance
