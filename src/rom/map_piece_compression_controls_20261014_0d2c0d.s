.setcpu "65816"
.segment "CODE"
.org $2C0D
map_control_0d2c0d:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
