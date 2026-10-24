.setcpu "65816"
.segment "CODE"
.org $6FCF
map_control_0c6fcf:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
