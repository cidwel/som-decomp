.setcpu "65816"
.segment "CODE"
.org $61D3
map_control_0e61d3:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
