.setcpu "65816"
.segment "CODE"
.org $12B9
map_control_0d12b9:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
