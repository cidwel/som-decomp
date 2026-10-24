.setcpu "65816"
.segment "CODE"
.org $4278
map_control_0f4278:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
