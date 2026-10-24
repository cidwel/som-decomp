.setcpu "65816"
.segment "CODE"
.org $1F8B
map_control_0d1f8b:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
