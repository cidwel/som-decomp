.setcpu "65816"
.segment "CODE"
.org $F0EF
map_control_0ef0ef:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
