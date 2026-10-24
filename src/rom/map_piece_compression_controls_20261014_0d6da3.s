.setcpu "65816"
.segment "CODE"
.org $6DA3
map_control_0d6da3:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
