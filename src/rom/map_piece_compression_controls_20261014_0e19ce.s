.setcpu "65816"
.segment "CODE"
.org $19CE
map_control_0e19ce:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
