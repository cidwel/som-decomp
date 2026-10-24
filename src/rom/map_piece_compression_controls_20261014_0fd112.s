.setcpu "65816"
.segment "CODE"
.org $D112
map_control_0fd112:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
