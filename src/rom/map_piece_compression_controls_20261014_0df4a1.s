.setcpu "65816"
.segment "CODE"
.org $F4A1
map_control_0df4a1:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
