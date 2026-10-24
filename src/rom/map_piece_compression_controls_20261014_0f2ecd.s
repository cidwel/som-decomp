.setcpu "65816"
.segment "CODE"
.org $2ECD
map_control_0f2ecd:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
