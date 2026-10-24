.setcpu "65816"
.segment "CODE"
.org $7FF2
map_control_0d7ff2:
    .byte $E0 ; previous-row copy escape
    .byte $9C ; row-distance/count
