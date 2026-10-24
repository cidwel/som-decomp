.setcpu "65816"
.segment "CODE"
.org $FC86
map_control_0ffc86:
    .byte $C3 ; same-value copy count/distance
