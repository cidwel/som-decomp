.setcpu "65816"
.segment "CODE"
.org $ED26
map_control_0eed26:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
