.setcpu "65816"
.segment "CODE"
.org $54FF
map_control_0f54ff:
    .byte $C4 ; same-value copy count/distance
