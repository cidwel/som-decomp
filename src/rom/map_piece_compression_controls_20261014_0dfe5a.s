.setcpu "65816"
.segment "CODE"
.org $FE5A
map_control_0dfe5a:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
