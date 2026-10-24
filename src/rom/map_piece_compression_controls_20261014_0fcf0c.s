.setcpu "65816"
.segment "CODE"
.org $CF0C
map_control_0fcf0c:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
