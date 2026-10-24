.setcpu "65816"
.segment "CODE"
.org $7696
map_control_0e7696:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
