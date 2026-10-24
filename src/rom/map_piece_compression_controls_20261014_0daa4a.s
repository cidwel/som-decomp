.setcpu "65816"
.segment "CODE"
.org $AA4A
map_control_0daa4a:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
