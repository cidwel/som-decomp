.setcpu "65816"
.segment "CODE"
.org $76BD
map_control_0d76bd:
    .byte $E0 ; previous-row copy escape
    .byte $46 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
