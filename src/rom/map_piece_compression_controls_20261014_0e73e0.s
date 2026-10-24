.setcpu "65816"
.segment "CODE"
.org $73E0
map_control_0e73e0:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
