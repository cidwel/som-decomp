.setcpu "65816"
.segment "CODE"
.org $6041
map_control_0f6041:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
