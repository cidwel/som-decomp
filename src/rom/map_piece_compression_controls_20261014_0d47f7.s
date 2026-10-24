.setcpu "65816"
.segment "CODE"
.org $47F7
map_control_0d47f7:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
