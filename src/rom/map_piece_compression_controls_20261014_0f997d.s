.setcpu "65816"
.segment "CODE"
.org $997D
map_control_0f997d:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
