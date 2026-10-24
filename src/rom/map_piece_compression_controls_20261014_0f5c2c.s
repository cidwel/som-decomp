.setcpu "65816"
.segment "CODE"
.org $5C2C
map_control_0f5c2c:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
