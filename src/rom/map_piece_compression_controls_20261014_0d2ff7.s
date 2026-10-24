.setcpu "65816"
.segment "CODE"
.org $2FF7
map_control_0d2ff7:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
