.setcpu "65816"
.segment "CODE"
.org $7985
map_control_0f7985:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
