.setcpu "65816"
.segment "CODE"
.org $B408
map_control_0eb408:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
