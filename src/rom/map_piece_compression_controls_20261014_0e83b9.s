.setcpu "65816"
.segment "CODE"
.org $83B9
map_control_0e83b9:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
