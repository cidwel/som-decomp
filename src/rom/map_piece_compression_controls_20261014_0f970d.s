.setcpu "65816"
.segment "CODE"
.org $970D
map_control_0f970d:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
