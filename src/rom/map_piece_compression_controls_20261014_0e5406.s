.setcpu "65816"
.segment "CODE"
.org $5406
map_control_0e5406:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
