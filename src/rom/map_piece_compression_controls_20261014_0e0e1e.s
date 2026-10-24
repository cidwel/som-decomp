.setcpu "65816"
.segment "CODE"
.org $0E1E
map_control_0e0e1e:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
