.setcpu "65816"
.segment "CODE"
.org $76CE
map_control_0d76ce:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
