.setcpu "65816"
.segment "CODE"
.org $2425
map_control_0c2425:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
