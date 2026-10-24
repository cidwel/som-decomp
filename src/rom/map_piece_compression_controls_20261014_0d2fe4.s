.setcpu "65816"
.segment "CODE"
.org $2FE4
map_control_0d2fe4:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
