.setcpu "65816"
.segment "CODE"
.org $395B
map_control_0f395b:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
