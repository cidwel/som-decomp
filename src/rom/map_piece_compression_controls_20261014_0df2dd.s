.setcpu "65816"
.segment "CODE"
.org $F2DD
map_control_0df2dd:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
