.setcpu "65816"
.segment "CODE"
.org $AEEB
map_control_0faeeb:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
