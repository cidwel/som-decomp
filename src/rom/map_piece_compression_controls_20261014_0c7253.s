.setcpu "65816"
.segment "CODE"
.org $7253
map_control_0c7253:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
