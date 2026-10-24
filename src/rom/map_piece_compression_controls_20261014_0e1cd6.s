.setcpu "65816"
.segment "CODE"
.org $1CD6
map_control_0e1cd6:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
