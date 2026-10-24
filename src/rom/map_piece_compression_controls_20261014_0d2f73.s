.setcpu "65816"
.segment "CODE"
.org $2F73
map_control_0d2f73:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
