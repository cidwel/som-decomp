.setcpu "65816"
.segment "CODE"
.org $B2E2
map_control_0eb2e2:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
