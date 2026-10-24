.setcpu "65816"
.segment "CODE"
.org $F79D
map_control_0ff79d:
    .byte $D1 ; same-value copy count/distance
