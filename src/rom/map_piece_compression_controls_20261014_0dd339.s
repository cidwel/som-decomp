.setcpu "65816"
.segment "CODE"
.org $D339
map_control_0dd339:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
