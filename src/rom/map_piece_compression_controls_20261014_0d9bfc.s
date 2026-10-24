.setcpu "65816"
.segment "CODE"
.org $9BFC
map_control_0d9bfc:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
