.setcpu "65816"
.segment "CODE"
.org $7526
map_control_0f7526:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
