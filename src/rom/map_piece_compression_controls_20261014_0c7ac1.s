.setcpu "65816"
.segment "CODE"
.org $7AC1
map_control_0c7ac1:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
