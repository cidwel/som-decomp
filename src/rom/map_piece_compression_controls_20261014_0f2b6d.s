.setcpu "65816"
.segment "CODE"
.org $2B6D
map_control_0f2b6d:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $50 ; row-distance/count
