.setcpu "65816"
.segment "CODE"
.org $CF7F
map_control_0ecf7f:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
