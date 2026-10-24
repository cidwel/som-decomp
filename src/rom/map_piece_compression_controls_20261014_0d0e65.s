.setcpu "65816"
.segment "CODE"
.org $0E65
map_control_0d0e65:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
