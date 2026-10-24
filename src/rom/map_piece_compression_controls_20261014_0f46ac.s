.setcpu "65816"
.segment "CODE"
.org $46AC
map_control_0f46ac:
    .byte $E0 ; previous-row copy escape
    .byte $54 ; row-distance/count
