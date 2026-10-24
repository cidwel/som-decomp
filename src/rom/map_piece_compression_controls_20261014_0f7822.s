.setcpu "65816"
.segment "CODE"
.org $7822
map_control_0f7822:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
