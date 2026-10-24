.setcpu "65816"
.segment "CODE"
.org $52B0
map_control_0e52b0:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
