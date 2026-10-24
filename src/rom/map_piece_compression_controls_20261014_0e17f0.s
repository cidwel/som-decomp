.setcpu "65816"
.segment "CODE"
.org $17F0
map_control_0e17f0:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
