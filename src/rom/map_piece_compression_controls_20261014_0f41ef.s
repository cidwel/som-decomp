.setcpu "65816"
.segment "CODE"
.org $41EF
map_control_0f41ef:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
