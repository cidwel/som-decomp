.setcpu "65816"
.segment "CODE"
.org $8B6D
map_control_0c8b6d:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
