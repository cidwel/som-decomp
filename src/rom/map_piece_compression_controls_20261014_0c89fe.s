.setcpu "65816"
.segment "CODE"
.org $89FE
map_control_0c89fe:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
