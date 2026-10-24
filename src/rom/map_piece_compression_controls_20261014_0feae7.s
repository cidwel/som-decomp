.setcpu "65816"
.segment "CODE"
.org $EAE7
map_control_0feae7:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
