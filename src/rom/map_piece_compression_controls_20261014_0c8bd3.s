.setcpu "65816"
.segment "CODE"
.org $8BD3
map_control_0c8bd3:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
