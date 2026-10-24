.setcpu "65816"
.segment "CODE"
.org $6C0E
map_control_0f6c0e:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
