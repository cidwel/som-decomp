.setcpu "65816"
.segment "CODE"
.org $4B31
map_control_0d4b31:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
