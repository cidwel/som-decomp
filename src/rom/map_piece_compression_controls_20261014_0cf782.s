.setcpu "65816"
.segment "CODE"
.org $F782
map_control_0cf782:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
