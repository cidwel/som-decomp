.setcpu "65816"
.segment "CODE"
.org $3A6E
map_control_0c3a6e:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
