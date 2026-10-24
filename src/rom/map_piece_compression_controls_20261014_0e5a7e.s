.setcpu "65816"
.segment "CODE"
.org $5A7E
map_control_0e5a7e:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
