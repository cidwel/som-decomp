.setcpu "65816"
.segment "CODE"
.org $1F0A
map_control_0f1f0a:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
