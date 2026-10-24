.setcpu "65816"
.segment "CODE"
.org $E4C0
map_control_0de4c0:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
