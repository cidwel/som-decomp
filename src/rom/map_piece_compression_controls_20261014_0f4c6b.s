.setcpu "65816"
.segment "CODE"
.org $4C6B
map_control_0f4c6b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $38 ; distance low bit/count
