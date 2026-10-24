.setcpu "65816"
.segment "CODE"
.org $BF21
map_control_0dbf21:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
