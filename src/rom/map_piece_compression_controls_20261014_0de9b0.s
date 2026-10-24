.setcpu "65816"
.segment "CODE"
.org $E9B0
map_control_0de9b0:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
