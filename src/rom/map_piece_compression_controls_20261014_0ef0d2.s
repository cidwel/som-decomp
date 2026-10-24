.setcpu "65816"
.segment "CODE"
.org $F0D2
map_control_0ef0d2:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
