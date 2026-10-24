.setcpu "65816"
.segment "CODE"
.org $465A
map_control_0d465a:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
