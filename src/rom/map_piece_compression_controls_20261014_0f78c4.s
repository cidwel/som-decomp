.setcpu "65816"
.segment "CODE"
.org $78C4
map_control_0f78c4:
    .byte $E0 ; previous-row copy escape
    .byte $A9 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
