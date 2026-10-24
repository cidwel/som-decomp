.setcpu "65816"
.segment "CODE"
.org $AC84
map_control_0eac84:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
