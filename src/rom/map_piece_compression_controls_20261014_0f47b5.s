.setcpu "65816"
.segment "CODE"
.org $47B5
map_control_0f47b5:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
