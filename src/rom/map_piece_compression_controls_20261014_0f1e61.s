.setcpu "65816"
.segment "CODE"
.org $1E61
map_control_0f1e61:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
