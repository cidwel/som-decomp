.setcpu "65816"
.segment "CODE"
.org $0D66
map_control_0c0d66:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
