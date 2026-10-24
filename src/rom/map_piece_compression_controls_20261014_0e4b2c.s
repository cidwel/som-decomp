.setcpu "65816"
.segment "CODE"
.org $4B2C
map_control_0e4b2c:
    .byte $E0 ; previous-row copy escape
    .byte $AD ; row-distance/count
