.setcpu "65816"
.segment "CODE"
.org $9F99
map_control_0d9f99:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
