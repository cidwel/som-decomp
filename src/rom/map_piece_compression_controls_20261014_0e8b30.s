.setcpu "65816"
.segment "CODE"
.org $8B30
map_control_0e8b30:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
