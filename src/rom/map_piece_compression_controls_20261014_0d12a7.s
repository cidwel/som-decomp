.setcpu "65816"
.segment "CODE"
.org $12A7
map_control_0d12a7:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
