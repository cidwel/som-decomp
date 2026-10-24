.setcpu "65816"
.segment "CODE"
.org $211E
map_control_0d211e:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
