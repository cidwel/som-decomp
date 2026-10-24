.setcpu "65816"
.segment "CODE"
.org $63A3
map_control_0c63a3:
    .byte $E0 ; previous-row copy escape
    .byte $44 ; row-distance/count
