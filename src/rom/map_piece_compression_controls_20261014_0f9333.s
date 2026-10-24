.setcpu "65816"
.segment "CODE"
.org $9333
map_control_0f9333:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
