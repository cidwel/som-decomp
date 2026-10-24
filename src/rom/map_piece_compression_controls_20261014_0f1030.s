.setcpu "65816"
.segment "CODE"
.org $1030
map_control_0f1030:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
