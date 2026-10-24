.setcpu "65816"
.segment "CODE"
.org $4AB2
map_control_0c4ab2:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
