.setcpu "65816"
.segment "CODE"
.org $F5BF
map_control_0ff5bf:
    .byte $D4 ; same-value copy count/distance
