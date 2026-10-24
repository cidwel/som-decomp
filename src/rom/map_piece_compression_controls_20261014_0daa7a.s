.setcpu "65816"
.segment "CODE"
.org $AA7A
map_control_0daa7a:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
