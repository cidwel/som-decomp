.setcpu "65816"
.segment "CODE"
.org $ED18
map_control_0eed18:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
