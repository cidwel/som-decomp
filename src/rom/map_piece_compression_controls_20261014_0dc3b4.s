.setcpu "65816"
.segment "CODE"
.org $C3B4
map_control_0dc3b4:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
