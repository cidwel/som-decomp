.setcpu "65816"
.segment "CODE"
.org $9342
map_control_0f9342:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
