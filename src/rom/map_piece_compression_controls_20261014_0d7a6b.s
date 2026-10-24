.setcpu "65816"
.segment "CODE"
.org $7A6B
map_control_0d7a6b:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
