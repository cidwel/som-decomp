.setcpu "65816"
.segment "CODE"
.org $B4CA
map_control_0fb4ca:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
