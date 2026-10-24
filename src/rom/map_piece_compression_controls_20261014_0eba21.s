.setcpu "65816"
.segment "CODE"
.org $BA21
map_control_0eba21:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
