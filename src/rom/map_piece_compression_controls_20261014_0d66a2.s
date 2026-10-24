.setcpu "65816"
.segment "CODE"
.org $66A2
map_control_0d66a2:
    .byte $E0 ; previous-row copy escape
    .byte $3E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $BB ; row-distance/count
