.setcpu "65816"
.segment "CODE"
.org $76EE
map_control_0f76ee:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
