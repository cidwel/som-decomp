.setcpu "65816"
.segment "CODE"
.org $EEC6
map_control_0eeec6:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
