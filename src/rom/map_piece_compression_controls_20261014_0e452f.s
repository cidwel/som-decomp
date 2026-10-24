.setcpu "65816"
.segment "CODE"
.org $452F
map_control_0e452f:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
