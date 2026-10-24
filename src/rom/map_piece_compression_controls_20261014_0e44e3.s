.setcpu "65816"
.segment "CODE"
.org $44E3
map_control_0e44e3:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
