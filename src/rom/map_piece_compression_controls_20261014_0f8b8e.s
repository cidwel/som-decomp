.setcpu "65816"
.segment "CODE"
.org $8B8E
map_control_0f8b8e:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
