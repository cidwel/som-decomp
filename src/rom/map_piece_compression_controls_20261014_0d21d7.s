.setcpu "65816"
.segment "CODE"
.org $21D7
map_control_0d21d7:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
