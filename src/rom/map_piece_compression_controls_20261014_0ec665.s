.setcpu "65816"
.segment "CODE"
.org $C665
map_control_0ec665:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
