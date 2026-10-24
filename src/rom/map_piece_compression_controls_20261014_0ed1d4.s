.setcpu "65816"
.segment "CODE"
.org $D1D4
map_control_0ed1d4:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
