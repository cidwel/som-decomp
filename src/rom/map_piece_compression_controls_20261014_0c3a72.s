.setcpu "65816"
.segment "CODE"
.org $3A72
map_control_0c3a72:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
