.setcpu "65816"
.segment "CODE"
.org $1C5B
map_control_0d1c5b:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
