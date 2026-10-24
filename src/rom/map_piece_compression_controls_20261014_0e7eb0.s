.setcpu "65816"
.segment "CODE"
.org $7EB0
map_control_0e7eb0:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
