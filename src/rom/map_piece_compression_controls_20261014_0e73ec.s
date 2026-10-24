.setcpu "65816"
.segment "CODE"
.org $73EC
map_control_0e73ec:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
