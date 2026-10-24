.setcpu "65816"
.segment "CODE"
.org $2C1A
map_control_0d2c1a:
    .byte $E0 ; previous-row copy escape
    .byte $3B ; row-distance/count
