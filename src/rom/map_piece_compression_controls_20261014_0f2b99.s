.setcpu "65816"
.segment "CODE"
.org $2B99
map_control_0f2b99:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
