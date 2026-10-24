.setcpu "65816"
.segment "CODE"
.org $C482
map_control_0fc482:
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
