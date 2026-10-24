.setcpu "65816"
.segment "CODE"
.org $5B90
map_control_0d5b90:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
