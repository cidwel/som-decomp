.setcpu "65816"
.segment "CODE"
.org $77E5
map_control_0e77e5:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
