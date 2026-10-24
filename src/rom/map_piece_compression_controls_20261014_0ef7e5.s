.setcpu "65816"
.segment "CODE"
.org $F7E5
map_control_0ef7e5:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
