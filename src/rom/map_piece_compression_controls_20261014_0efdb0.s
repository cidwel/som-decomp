.setcpu "65816"
.segment "CODE"
.org $FDB0
map_control_0efdb0:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
