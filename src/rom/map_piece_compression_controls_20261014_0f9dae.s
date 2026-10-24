.setcpu "65816"
.segment "CODE"
.org $9DAE
map_control_0f9dae:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
