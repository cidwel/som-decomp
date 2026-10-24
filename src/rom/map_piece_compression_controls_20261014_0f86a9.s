.setcpu "65816"
.segment "CODE"
.org $86A9
map_control_0f86a9:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
