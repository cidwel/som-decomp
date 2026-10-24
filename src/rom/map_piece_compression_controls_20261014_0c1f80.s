.setcpu "65816"
.segment "CODE"
.org $1F80
map_control_0c1f80:
    .byte $D6 ; same-value copy count/distance
