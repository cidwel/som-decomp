.setcpu "65816"
.segment "CODE"
.org $44BD
map_control_0c44bd:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
