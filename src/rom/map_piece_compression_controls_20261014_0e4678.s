.setcpu "65816"
.segment "CODE"
.org $4678
map_control_0e4678:
    .byte $EB ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
