.setcpu "65816"
.segment "CODE"
.org $80EC
map_control_0d80ec:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
