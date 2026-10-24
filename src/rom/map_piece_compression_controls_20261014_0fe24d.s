.setcpu "65816"
.segment "CODE"
.org $E24D
map_control_0fe24d:
    .byte $EA ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
