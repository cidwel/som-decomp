.setcpu "65816"
.segment "CODE"
.org $2370
map_control_0d2370:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
