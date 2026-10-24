.setcpu "65816"
.segment "CODE"
.org $47E6
map_control_0d47e6:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
