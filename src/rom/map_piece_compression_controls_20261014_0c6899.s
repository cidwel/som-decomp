.setcpu "65816"
.segment "CODE"
.org $6899
map_control_0c6899:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
