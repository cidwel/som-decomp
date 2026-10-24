.setcpu "65816"
.segment "CODE"
.org $4294
map_control_0c4294:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
