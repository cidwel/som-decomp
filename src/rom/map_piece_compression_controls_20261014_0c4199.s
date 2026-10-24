.setcpu "65816"
.segment "CODE"
.org $4199
map_control_0c4199:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
