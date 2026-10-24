.setcpu "65816"
.segment "CODE"
.org $7466
map_control_0e7466:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
