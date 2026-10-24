.setcpu "65816"
.segment "CODE"
.org $6D7C
map_control_0e6d7c:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
