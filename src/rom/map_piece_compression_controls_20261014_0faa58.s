.setcpu "65816"
.segment "CODE"
.org $AA58
map_control_0faa58:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
