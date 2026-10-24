.setcpu "65816"
.segment "CODE"
.org $F99A
map_control_0ff99a:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
