.setcpu "65816"
.segment "CODE"
.org $5E4A
map_control_0e5e4a:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
