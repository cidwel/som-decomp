.setcpu "65816"
.segment "CODE"
.org $A692
map_control_0fa692:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
