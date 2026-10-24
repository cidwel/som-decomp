.setcpu "65816"
.segment "CODE"
.org $F8DD
map_control_0ff8dd:
    .byte $D3 ; same-value copy count/distance
