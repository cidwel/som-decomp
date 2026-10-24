.setcpu "65816"
.segment "CODE"
.org $9E50
map_control_0d9e50:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
