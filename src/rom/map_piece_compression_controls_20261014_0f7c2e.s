.setcpu "65816"
.segment "CODE"
.org $7C2E
map_control_0f7c2e:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
