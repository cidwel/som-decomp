.setcpu "65816"
.segment "CODE"
.org $4C01
map_control_0f4c01:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
