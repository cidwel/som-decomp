.setcpu "65816"
.segment "CODE"
.org $960E
map_control_0f960e:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
