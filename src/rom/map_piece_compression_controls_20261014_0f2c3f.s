.setcpu "65816"
.segment "CODE"
.org $2C3F
map_control_0f2c3f:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
