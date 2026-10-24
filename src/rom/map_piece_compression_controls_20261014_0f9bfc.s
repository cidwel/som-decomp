.setcpu "65816"
.segment "CODE"
.org $9BFC
map_control_0f9bfc:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
