.setcpu "65816"
.segment "CODE"
.org $F7F2
map_control_0ff7f2:
    .byte $D3 ; same-value copy count/distance
