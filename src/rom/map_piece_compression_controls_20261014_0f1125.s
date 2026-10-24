.setcpu "65816"
.segment "CODE"
.org $1125
map_control_0f1125:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
