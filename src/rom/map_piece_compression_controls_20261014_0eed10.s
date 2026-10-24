.setcpu "65816"
.segment "CODE"
.org $ED10
map_control_0eed10:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
