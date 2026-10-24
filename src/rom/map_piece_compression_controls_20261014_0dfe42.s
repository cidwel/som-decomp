.setcpu "65816"
.segment "CODE"
.org $FE42
map_control_0dfe42:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
