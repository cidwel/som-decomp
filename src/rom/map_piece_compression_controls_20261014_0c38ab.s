.setcpu "65816"
.segment "CODE"
.org $38AB
map_control_0c38ab:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
