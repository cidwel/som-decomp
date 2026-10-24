.setcpu "65816"
.segment "CODE"
.org $2B39
map_control_0d2b39:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
