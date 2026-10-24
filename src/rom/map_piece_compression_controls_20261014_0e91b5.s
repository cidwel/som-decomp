.setcpu "65816"
.segment "CODE"
.org $91B5
map_control_0e91b5:
    .byte $E0 ; previous-row copy escape
    .byte $A8 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
