.setcpu "65816"
.segment "CODE"
.org $045F
map_control_0e045f:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
