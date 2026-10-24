.setcpu "65816"
.segment "CODE"
.org $73D2
map_control_0e73d2:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
