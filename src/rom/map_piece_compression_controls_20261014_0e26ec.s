.setcpu "65816"
.segment "CODE"
.org $26EC
map_control_0e26ec:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
