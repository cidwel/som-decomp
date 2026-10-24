.setcpu "65816"
.segment "CODE"
.org $35A1
map_control_0d35a1:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
