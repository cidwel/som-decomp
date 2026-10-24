.setcpu "65816"
.segment "CODE"
.org $6E7E
map_control_0d6e7e:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
