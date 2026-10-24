.setcpu "65816"
.segment "CODE"
.org $CFB8
map_control_0ecfb8:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
