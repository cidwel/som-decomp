.setcpu "65816"
.segment "CODE"
.org $32C9
map_control_0d32c9:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
