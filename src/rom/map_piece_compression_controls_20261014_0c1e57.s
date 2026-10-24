.setcpu "65816"
.segment "CODE"
.org $1E57
map_control_0c1e57:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
