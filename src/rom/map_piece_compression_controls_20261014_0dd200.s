.setcpu "65816"
.segment "CODE"
.org $D200
map_control_0dd200:
    .byte $C2 ; same-value copy count/distance
