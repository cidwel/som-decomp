.setcpu "65816"
.segment "CODE"
.org $3698
map_control_0d3698:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
