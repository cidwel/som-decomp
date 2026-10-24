.setcpu "65816"
.segment "CODE"
.org $9A17
map_control_0f9a17:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
