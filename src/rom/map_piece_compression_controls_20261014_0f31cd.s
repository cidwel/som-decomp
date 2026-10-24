.setcpu "65816"
.segment "CODE"
.org $31CD
map_control_0f31cd:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
