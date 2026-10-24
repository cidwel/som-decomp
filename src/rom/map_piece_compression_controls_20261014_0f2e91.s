.setcpu "65816"
.segment "CODE"
.org $2E91
map_control_0f2e91:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count
