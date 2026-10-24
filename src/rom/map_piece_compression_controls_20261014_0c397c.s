.setcpu "65816"
.segment "CODE"
.org $397C
map_control_0c397c:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
