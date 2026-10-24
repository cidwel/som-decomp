.setcpu "65816"
.segment "CODE"
.org $2E46
map_control_0d2e46:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
