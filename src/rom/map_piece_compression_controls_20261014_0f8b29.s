.setcpu "65816"
.segment "CODE"
.org $8B29
map_control_0f8b29:
    .byte $E0 ; previous-row copy escape
    .byte $9F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $45 ; row-distance/count
