.setcpu "65816"
.segment "CODE"
.org $47DC
map_control_0d47dc:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
