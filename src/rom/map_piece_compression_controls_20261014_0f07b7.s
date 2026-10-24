.setcpu "65816"
.segment "CODE"
.org $07B7
map_control_0f07b7:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
