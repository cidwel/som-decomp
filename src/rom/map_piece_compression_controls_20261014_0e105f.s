.setcpu "65816"
.segment "CODE"
.org $105F
map_control_0e105f:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $0A ; distance low bit/count
