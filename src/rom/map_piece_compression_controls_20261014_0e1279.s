.setcpu "65816"
.segment "CODE"
.org $1279
map_control_0e1279:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
