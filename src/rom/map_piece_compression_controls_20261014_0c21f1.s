.setcpu "65816"
.segment "CODE"
.org $21F1
map_control_0c21f1:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
