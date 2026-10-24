.setcpu "65816"
.segment "CODE"
.org $0C35
map_control_0e0c35:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
