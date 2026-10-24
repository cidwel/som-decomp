.setcpu "65816"
.segment "CODE"
.org $DE09
map_control_0dde09:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
