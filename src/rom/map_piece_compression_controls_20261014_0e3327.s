.setcpu "65816"
.segment "CODE"
.org $3327
map_control_0e3327:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
