.setcpu "65816"
.segment "CODE"
.org $37A4
map_control_0f37a4:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
