.setcpu "65816"
.segment "CODE"
.org $9E96
map_control_0d9e96:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
