.setcpu "65816"
.segment "CODE"
.org $FF89
map_control_0eff89:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
