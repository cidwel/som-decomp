.setcpu "65816"
.segment "CODE"
.org $E12A
map_control_0de12a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
