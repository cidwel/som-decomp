.setcpu "65816"
.segment "CODE"
.org $28F6
map_control_0f28f6:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
