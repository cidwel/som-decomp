.setcpu "65816"
.segment "CODE"
.org $1E42
map_control_0f1e42:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
