.setcpu "65816"
.segment "CODE"
.org $74D0
map_control_0f74d0:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
