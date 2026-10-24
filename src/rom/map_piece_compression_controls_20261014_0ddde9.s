.setcpu "65816"
.segment "CODE"
.org $DDE9
map_control_0ddde9:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
