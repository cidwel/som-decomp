.setcpu "65816"
.segment "CODE"
.org $4CE2
map_control_0c4ce2:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
