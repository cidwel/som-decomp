.setcpu "65816"
.segment "CODE"
.org $E350
map_control_0de350:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
