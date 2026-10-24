.setcpu "65816"
.segment "CODE"
.org $2FF7
map_control_0f2ff7:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
