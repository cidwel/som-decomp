.setcpu "65816"
.segment "CODE"
.org $AC5C
map_control_0fac5c:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
