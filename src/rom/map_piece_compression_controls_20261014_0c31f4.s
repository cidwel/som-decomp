.setcpu "65816"
.segment "CODE"
.org $31F4
map_control_0c31f4:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
