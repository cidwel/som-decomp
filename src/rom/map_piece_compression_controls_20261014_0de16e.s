.setcpu "65816"
.segment "CODE"
.org $E16E
map_control_0de16e:
    .byte $ED ; backreference distance high bits
    .byte $06 ; distance low bit/count
