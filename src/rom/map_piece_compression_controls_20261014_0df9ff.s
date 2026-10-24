.setcpu "65816"
.segment "CODE"
.org $F9FF
map_control_0df9ff:
    .byte $D1 ; same-value copy count/distance
