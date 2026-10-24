.setcpu "65816"
.segment "CODE"
.org $92DC
map_control_0d92dc:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
