.setcpu "65816"
.segment "CODE"
.org $FC5D
map_control_0ffc5d:
    .byte $D1 ; same-value copy count/distance
