.setcpu "65816"
.segment "CODE"
.org $42F2
map_control_0e42f2:
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
