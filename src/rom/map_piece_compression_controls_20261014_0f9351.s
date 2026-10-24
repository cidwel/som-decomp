.setcpu "65816"
.segment "CODE"
.org $9351
map_control_0f9351:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
