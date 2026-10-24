.setcpu "65816"
.segment "CODE"
.org $122C
map_control_0e122c:
    .byte $E8 ; backreference distance high bits
    .byte $66 ; distance low bit/count
