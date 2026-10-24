.setcpu "65816"
.segment "CODE"
.org $9B2D
map_control_0f9b2d:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
