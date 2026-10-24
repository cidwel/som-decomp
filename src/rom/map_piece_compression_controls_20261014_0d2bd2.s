.setcpu "65816"
.segment "CODE"
.org $2BD2
map_control_0d2bd2:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
