.setcpu "65816"
.segment "CODE"
.org $2FEE
map_control_0c2fee:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
