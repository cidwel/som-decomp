.setcpu "65816"
.segment "CODE"
.org $3F5E
map_control_0f3f5e:
    .byte $EA ; backreference distance high bits
    .byte $90 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $38 ; distance low bit/count
