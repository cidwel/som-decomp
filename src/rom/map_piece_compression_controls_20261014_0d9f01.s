.setcpu "65816"
.segment "CODE"
.org $9F01
map_control_0d9f01:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
