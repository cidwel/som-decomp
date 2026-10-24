.setcpu "65816"
.segment "CODE"
.org $3C16
map_control_0d3c16:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
