.setcpu "65816"
.segment "CODE"
.org $ED7C
map_control_0eed7c:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
