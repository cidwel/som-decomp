.setcpu "65816"
.segment "CODE"
.org $11B0
map_control_0d11b0:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
