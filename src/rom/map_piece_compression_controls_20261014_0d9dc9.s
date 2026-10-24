.setcpu "65816"
.segment "CODE"
.org $9DC9
map_control_0d9dc9:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
