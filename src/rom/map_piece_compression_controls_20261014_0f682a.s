.setcpu "65816"
.segment "CODE"
.org $682A
map_control_0f682a:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
