.setcpu "65816"
.segment "CODE"
.org $8D4B
map_control_0d8d4b:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
