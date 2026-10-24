.setcpu "65816"
.segment "CODE"
.org $AA07
map_control_0faa07:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
