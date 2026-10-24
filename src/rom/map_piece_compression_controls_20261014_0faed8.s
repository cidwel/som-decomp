.setcpu "65816"
.segment "CODE"
.org $AED8
map_control_0faed8:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
