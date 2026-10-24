.setcpu "65816"
.segment "CODE"
.org $73AB
map_control_0e73ab:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
