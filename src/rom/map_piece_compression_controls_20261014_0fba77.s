.setcpu "65816"
.segment "CODE"
.org $BA77
map_control_0fba77:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
