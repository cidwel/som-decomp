.setcpu "65816"
.segment "CODE"
.org $3FF3
map_control_0d3ff3:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
