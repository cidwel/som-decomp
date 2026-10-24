.setcpu "65816"
.segment "CODE"
.org $2C36
map_control_0d2c36:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
