.setcpu "65816"
.segment "CODE"
.org $72D9
map_control_0f72d9:
    .byte $E8 ; backreference distance high bits
    .byte $63 ; distance low bit/count
