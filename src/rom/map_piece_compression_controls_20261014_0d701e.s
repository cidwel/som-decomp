.setcpu "65816"
.segment "CODE"
.org $701E
map_control_0d701e:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
