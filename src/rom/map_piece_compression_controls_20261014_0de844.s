.setcpu "65816"
.segment "CODE"
.org $E844
map_control_0de844:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
