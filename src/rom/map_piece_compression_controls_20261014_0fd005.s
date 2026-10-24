.setcpu "65816"
.segment "CODE"
.org $D005
map_control_0fd005:
    .byte $C2 ; same-value copy count/distance
