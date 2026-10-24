.setcpu "65816"
.segment "CODE"
.org $6C25
map_control_0f6c25:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
