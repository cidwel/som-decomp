.setcpu "65816"
.segment "CODE"
.org $B220
map_control_0fb220:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
