.setcpu "65816"
.segment "CODE"
.org $35CB
map_control_0c35cb:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
