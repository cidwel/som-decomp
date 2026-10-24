.setcpu "65816"
.segment "CODE"
.org $315E
map_control_0d315e:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
