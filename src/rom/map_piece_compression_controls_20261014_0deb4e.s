.setcpu "65816"
.segment "CODE"
.org $EB4E
map_control_0deb4e:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
