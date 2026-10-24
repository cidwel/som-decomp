.setcpu "65816"
.segment "CODE"
.org $42FA
map_control_0f42fa:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
