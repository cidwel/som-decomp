.setcpu "65816"
.segment "CODE"
.org $1451
map_control_0e1451:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
