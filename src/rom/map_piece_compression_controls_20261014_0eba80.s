.setcpu "65816"
.segment "CODE"
.org $BA80
map_control_0eba80:
    .byte $CE ; same-value copy count/distance
