.setcpu "65816"
.segment "CODE"
.org $F422
map_control_0ff422:
    .byte $C2 ; same-value copy count/distance
