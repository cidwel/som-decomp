.setcpu "65816"
.segment "CODE"
.org $295D
map_control_0c295d:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
