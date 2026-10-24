.setcpu "65816"
.segment "CODE"
.org $5F07
map_control_0d5f07:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
