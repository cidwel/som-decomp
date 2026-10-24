.setcpu "65816"
.segment "CODE"
.org $10DD
map_control_0c10dd:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
