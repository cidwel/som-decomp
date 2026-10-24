.setcpu "65816"
.segment "CODE"
.org $7C0D
map_control_0c7c0d:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
