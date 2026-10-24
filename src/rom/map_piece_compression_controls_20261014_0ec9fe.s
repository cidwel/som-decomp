.setcpu "65816"
.segment "CODE"
.org $C9FE
map_control_0ec9fe:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
