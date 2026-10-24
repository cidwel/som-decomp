.setcpu "65816"
.segment "CODE"
.org $1626
map_control_0e1626:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
