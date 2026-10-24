.setcpu "65816"
.segment "CODE"
.org $6D7C
map_control_0c6d7c:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
