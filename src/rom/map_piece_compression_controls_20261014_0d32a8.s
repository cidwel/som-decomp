.setcpu "65816"
.segment "CODE"
.org $32A8
map_control_0d32a8:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
