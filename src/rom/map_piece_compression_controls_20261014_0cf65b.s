.setcpu "65816"
.segment "CODE"
.org $F65B
map_control_0cf65b:
    .byte $F1 ; progressive-copy count
    .byte $D3 ; same-value copy count/distance
