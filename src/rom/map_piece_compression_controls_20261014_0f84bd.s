.setcpu "65816"
.segment "CODE"
.org $84BD
map_control_0f84bd:
    .byte $CC ; same-value copy count/distance
