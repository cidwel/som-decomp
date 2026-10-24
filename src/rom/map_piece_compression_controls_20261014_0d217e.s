.setcpu "65816"
.segment "CODE"
.org $217E
map_control_0d217e:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
