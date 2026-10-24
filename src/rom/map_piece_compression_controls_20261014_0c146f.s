.setcpu "65816"
.segment "CODE"
.org $146F
map_control_0c146f:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
