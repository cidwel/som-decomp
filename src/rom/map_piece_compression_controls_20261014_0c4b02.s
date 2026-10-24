.setcpu "65816"
.segment "CODE"
.org $4B02
map_control_0c4b02:
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count
