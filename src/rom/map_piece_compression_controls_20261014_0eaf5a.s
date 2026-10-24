.setcpu "65816"
.segment "CODE"
.org $AF5A
map_control_0eaf5a:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
