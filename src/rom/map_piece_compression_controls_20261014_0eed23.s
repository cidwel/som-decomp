.setcpu "65816"
.segment "CODE"
.org $ED23
map_control_0eed23:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
