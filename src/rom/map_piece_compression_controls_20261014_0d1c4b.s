.setcpu "65816"
.segment "CODE"
.org $1C4B
map_control_0d1c4b:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
