.setcpu "65816"
.segment "CODE"
.org $E52D
map_control_0de52d:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
