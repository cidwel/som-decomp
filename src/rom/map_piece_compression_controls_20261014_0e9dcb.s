.setcpu "65816"
.segment "CODE"
.org $9DCB
map_control_0e9dcb:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count
