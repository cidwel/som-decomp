.setcpu "65816"
.segment "CODE"
.org $5D5A
map_control_0e5d5a:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $30 ; distance low bit/count
