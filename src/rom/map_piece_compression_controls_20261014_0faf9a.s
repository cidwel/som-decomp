.setcpu "65816"
.segment "CODE"
.org $AF9A
map_control_0faf9a:
    .byte $E8 ; backreference distance high bits
    .byte $41 ; distance low bit/count
