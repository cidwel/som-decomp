.setcpu "65816"
.segment "CODE"
.org $1FCE
map_control_0f1fce:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
