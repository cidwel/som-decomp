.setcpu "65816"
.segment "CODE"
.org $5253
map_control_0c5253:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
