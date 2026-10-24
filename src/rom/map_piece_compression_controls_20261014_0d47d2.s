.setcpu "65816"
.segment "CODE"
.org $47D2
map_control_0d47d2:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
