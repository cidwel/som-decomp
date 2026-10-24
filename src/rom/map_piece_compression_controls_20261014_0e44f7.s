.setcpu "65816"
.segment "CODE"
.org $44F7
map_control_0e44f7:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
