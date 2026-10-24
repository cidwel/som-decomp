.setcpu "65816"
.segment "CODE"
.org $1FE9
map_control_0c1fe9:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
