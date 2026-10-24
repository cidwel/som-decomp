.setcpu "65816"
.segment "CODE"
.org $E279
map_control_0de279:
    .byte $D3 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
