.setcpu "65816"
.segment "CODE"
.org $28BD
map_control_0e28bd:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
