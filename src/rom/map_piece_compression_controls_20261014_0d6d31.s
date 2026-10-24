.setcpu "65816"
.segment "CODE"
.org $6D31
map_control_0d6d31:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
