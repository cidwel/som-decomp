.setcpu "65816"
.segment "CODE"
.org $DFD8
map_control_0ddfd8:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
