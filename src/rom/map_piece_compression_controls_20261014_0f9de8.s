.setcpu "65816"
.segment "CODE"
.org $9DE8
map_control_0f9de8:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
