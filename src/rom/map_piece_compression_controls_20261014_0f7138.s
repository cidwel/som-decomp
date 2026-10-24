.setcpu "65816"
.segment "CODE"
.org $7138
map_control_0f7138:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
