.setcpu "65816"
.segment "CODE"
.org $D3BD
map_control_0ed3bd:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
