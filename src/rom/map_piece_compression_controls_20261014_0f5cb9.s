.setcpu "65816"
.segment "CODE"
.org $5CB9
map_control_0f5cb9:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
