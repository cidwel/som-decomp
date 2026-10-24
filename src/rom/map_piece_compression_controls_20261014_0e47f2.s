.setcpu "65816"
.segment "CODE"
.org $47F2
map_control_0e47f2:
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
