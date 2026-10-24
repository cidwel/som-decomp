.setcpu "65816"
.segment "CODE"
.org $90A6
map_control_0d90a6:
    .byte $E0 ; previous-row copy escape
    .byte $8C ; row-distance/count
