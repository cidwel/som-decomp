.setcpu "65816"
.segment "CODE"
.org $5974
map_control_0c5974:
    .byte $EF ; backreference distance high bits
    .byte $91 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
