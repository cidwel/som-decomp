.setcpu "65816"
.segment "CODE"
.org $190A
map_control_0d190a:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
