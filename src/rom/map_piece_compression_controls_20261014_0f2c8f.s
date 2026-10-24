.setcpu "65816"
.segment "CODE"
.org $2C8F
map_control_0f2c8f:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
