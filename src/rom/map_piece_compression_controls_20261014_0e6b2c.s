.setcpu "65816"
.segment "CODE"
.org $6B2C
map_control_0e6b2c:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
