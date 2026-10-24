.setcpu "65816"
.segment "CODE"
.org $EB43
map_control_0eeb43:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
