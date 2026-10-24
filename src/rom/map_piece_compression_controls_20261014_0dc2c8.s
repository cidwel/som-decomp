.setcpu "65816"
.segment "CODE"
.org $C2C8
map_control_0dc2c8:
    .byte $E0 ; previous-row copy escape
    .byte $5F ; row-distance/count
