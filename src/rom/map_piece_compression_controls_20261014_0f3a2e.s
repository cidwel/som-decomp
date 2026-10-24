.setcpu "65816"
.segment "CODE"
.org $3A2E
map_control_0f3a2e:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
