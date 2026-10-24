.setcpu "65816"
.segment "CODE"
.org $CE35
map_control_0ece35:
    .byte $E0 ; previous-row copy escape
    .byte $44 ; row-distance/count
