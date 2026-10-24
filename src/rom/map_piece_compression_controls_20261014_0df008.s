.setcpu "65816"
.segment "CODE"
.org $F008
map_control_0df008:
    .byte $C6 ; same-value copy count/distance
