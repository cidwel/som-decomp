.setcpu "65816"
.segment "CODE"
.org $3616
map_control_0e3616:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $43 ; row-distance/count
