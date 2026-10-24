.setcpu "65816"
.segment "CODE"
.org $1B36
map_control_0f1b36:
    .byte $E0 ; previous-row copy escape
    .byte $53 ; row-distance/count
