.setcpu "65816"
.segment "CODE"
.org $7570
map_control_0e7570:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
