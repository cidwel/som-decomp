.setcpu "65816"
.segment "CODE"
.org $AAC2
map_control_0faac2:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
