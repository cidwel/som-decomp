.setcpu "65816"
.segment "CODE"
.org $2BAD
map_control_0f2bad:
    .byte $C2 ; same-value copy count/distance
