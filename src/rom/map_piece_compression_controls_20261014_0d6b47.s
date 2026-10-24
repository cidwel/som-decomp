.setcpu "65816"
.segment "CODE"
.org $6B47
map_control_0d6b47:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
