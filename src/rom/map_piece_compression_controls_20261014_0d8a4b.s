.setcpu "65816"
.segment "CODE"
.org $8A4B
map_control_0d8a4b:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
