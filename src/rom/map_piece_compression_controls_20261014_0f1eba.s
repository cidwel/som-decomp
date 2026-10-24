.setcpu "65816"
.segment "CODE"
.org $1EBA
map_control_0f1eba:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
