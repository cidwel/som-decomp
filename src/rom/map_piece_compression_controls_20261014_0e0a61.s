.setcpu "65816"
.segment "CODE"
.org $0A61
map_control_0e0a61:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $F1 ; progressive-copy count
