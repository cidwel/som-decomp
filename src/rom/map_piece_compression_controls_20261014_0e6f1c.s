.setcpu "65816"
.segment "CODE"
.org $6F1C
map_control_0e6f1c:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
