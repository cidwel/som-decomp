.setcpu "65816"
.segment "CODE"
.org $18B8
map_control_0e18b8:
    .byte $EB ; backreference distance high bits
    .byte $0A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
