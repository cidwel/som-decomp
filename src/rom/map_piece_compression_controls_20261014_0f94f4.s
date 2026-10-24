.setcpu "65816"
.segment "CODE"
.org $94F4
map_control_0f94f4:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
