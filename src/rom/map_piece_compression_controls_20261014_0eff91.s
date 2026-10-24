.setcpu "65816"
.segment "CODE"
.org $FF91
map_control_0eff91:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
