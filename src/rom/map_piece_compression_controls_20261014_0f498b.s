.setcpu "65816"
.segment "CODE"
.org $498B
map_control_0f498b:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
