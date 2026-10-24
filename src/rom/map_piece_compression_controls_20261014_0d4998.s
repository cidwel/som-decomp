.setcpu "65816"
.segment "CODE"
.org $4998
map_control_0d4998:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
