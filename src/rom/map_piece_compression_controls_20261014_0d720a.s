.setcpu "65816"
.segment "CODE"
.org $720A
map_control_0d720a:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
