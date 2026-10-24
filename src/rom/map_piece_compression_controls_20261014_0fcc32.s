.setcpu "65816"
.segment "CODE"
.org $CC32
map_control_0fcc32:
    .byte $C2 ; same-value copy count/distance
