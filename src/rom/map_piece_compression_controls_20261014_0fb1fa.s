.setcpu "65816"
.segment "CODE"
.org $B1FA
map_control_0fb1fa:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
