.setcpu "65816"
.segment "CODE"
.org $0B2C
map_control_0d0b2c:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
