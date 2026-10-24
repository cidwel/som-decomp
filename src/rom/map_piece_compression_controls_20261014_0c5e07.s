.setcpu "65816"
.segment "CODE"
.org $5E07
map_control_0c5e07:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $34 ; row-distance/count
