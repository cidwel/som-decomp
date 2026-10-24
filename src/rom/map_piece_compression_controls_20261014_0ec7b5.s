.setcpu "65816"
.segment "CODE"
.org $C7B5
map_control_0ec7b5:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
