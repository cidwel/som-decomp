.setcpu "65816"
.segment "CODE"
.org $C83A
map_control_0dc83a:
    .byte $E0 ; previous-row copy escape
    .byte $CE ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
