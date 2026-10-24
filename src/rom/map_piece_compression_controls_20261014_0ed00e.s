.setcpu "65816"
.segment "CODE"
.org $D00E
map_control_0ed00e:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
