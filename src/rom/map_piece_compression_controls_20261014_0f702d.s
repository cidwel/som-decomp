.setcpu "65816"
.segment "CODE"
.org $702D
map_control_0f702d:
    .byte $EB ; backreference distance high bits
    .byte $0C ; distance low bit/count
