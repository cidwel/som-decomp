.setcpu "65816"
.segment "CODE"
.org $32EF
map_control_0d32ef:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
