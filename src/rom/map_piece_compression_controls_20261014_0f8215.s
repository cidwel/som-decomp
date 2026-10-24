.setcpu "65816"
.segment "CODE"
.org $8215
map_control_0f8215:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
