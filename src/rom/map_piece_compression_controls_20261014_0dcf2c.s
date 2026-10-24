.setcpu "65816"
.segment "CODE"
.org $CF2C
map_control_0dcf2c:
    .byte $E0 ; previous-row copy escape
    .byte $3A ; row-distance/count
