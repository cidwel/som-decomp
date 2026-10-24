.setcpu "65816"
.segment "CODE"
.org $12CD
map_control_0d12cd:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
