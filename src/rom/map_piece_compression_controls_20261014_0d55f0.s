.setcpu "65816"
.segment "CODE"
.org $55F0
map_control_0d55f0:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
