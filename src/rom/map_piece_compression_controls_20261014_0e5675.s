.setcpu "65816"
.segment "CODE"
.org $5675
map_control_0e5675:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
