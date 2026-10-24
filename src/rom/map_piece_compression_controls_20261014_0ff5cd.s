.setcpu "65816"
.segment "CODE"
.org $F5CD
map_control_0ff5cd:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
