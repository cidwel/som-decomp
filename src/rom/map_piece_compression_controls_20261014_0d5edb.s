.setcpu "65816"
.segment "CODE"
.org $5EDB
map_control_0d5edb:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
