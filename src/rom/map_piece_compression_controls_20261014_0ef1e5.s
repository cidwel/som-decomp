.setcpu "65816"
.segment "CODE"
.org $F1E5
map_control_0ef1e5:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
