.setcpu "65816"
.segment "CODE"
.org $0577
map_control_0e0577:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
