.setcpu "65816"
.segment "CODE"
.org $C15A
map_control_0ec15a:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
