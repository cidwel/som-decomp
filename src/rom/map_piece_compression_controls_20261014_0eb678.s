.setcpu "65816"
.segment "CODE"
.org $B678
map_control_0eb678:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
