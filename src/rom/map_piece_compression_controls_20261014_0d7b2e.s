.setcpu "65816"
.segment "CODE"
.org $7B2E
map_control_0d7b2e:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
