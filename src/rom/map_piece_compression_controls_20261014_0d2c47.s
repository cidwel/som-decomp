.setcpu "65816"
.segment "CODE"
.org $2C47
map_control_0d2c47:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
