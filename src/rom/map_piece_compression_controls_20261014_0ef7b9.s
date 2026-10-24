.setcpu "65816"
.segment "CODE"
.org $F7B9
map_control_0ef7b9:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
