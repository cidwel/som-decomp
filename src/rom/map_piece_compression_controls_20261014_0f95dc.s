.setcpu "65816"
.segment "CODE"
.org $95DC
map_control_0f95dc:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
