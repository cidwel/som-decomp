.setcpu "65816"
.segment "CODE"
.org $1A64
map_control_0c1a64:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
