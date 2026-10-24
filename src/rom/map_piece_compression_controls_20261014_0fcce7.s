.setcpu "65816"
.segment "CODE"
.org $CCE7
map_control_0fcce7:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
