.setcpu "65816"
.segment "CODE"
.org $220A
map_control_0f220a:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
