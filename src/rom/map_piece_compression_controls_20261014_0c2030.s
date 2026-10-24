.setcpu "65816"
.segment "CODE"
.org $2030
map_control_0c2030:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
