.setcpu "65816"
.segment "CODE"
.org $421E
map_control_0f421e:
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
