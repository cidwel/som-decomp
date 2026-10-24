.setcpu "65816"
.segment "CODE"
.org $7ABD
map_control_0e7abd:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
