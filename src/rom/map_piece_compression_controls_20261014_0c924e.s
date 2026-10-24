.setcpu "65816"
.segment "CODE"
.org $924E
map_control_0c924e:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
