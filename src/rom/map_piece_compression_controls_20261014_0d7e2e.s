.setcpu "65816"
.segment "CODE"
.org $7E2E
map_control_0d7e2e:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
