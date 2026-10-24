.setcpu "65816"
.segment "CODE"
.org $7025
map_control_0f7025:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
