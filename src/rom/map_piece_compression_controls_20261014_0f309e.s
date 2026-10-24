.setcpu "65816"
.segment "CODE"
.org $309E
map_control_0f309e:
    .byte $E8 ; backreference distance high bits
    .byte $91 ; distance low bit/count
