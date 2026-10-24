.setcpu "65816"
.segment "CODE"
.org $35C7
map_control_0e35c7:
    .byte $ED ; backreference distance high bits
    .byte $07 ; distance low bit/count
