.setcpu "65816"
.segment "CODE"
.org $50E0
map_control_0e50e0:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
