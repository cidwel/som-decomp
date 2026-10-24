.setcpu "65816"
.segment "CODE"
.org $DAF8
map_control_0ddaf8:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
