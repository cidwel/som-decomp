.setcpu "65816"
.segment "CODE"
.org $DBB4
map_control_0fdbb4:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
