.setcpu "65816"
.segment "CODE"
.org $2299
map_control_0d2299:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
