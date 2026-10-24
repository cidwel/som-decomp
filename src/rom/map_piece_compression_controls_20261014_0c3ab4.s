.setcpu "65816"
.segment "CODE"
.org $3AB4
map_control_0c3ab4:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
