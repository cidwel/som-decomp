.setcpu "65816"
.segment "CODE"
.org $ED0A
map_control_0eed0a:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
