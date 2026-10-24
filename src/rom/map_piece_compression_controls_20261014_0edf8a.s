.setcpu "65816"
.segment "CODE"
.org $DF8A
map_control_0edf8a:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
