.setcpu "65816"
.segment "CODE"
.org $3072
map_control_0d3072:
    .byte $F3 ; progressive-copy count
    .byte $C5 ; same-value copy count/distance
