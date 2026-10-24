.setcpu "65816"
.segment "CODE"
.org $2F2C
map_control_0d2f2c:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
