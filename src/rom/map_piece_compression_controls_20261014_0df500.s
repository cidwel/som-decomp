.setcpu "65816"
.segment "CODE"
.org $F500
map_control_0df500:
    .byte $C9 ; same-value copy count/distance
