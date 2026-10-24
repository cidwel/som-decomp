.setcpu "65816"
.segment "CODE"
.org $82F2
map_control_0d82f2:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
