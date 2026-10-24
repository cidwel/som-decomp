.setcpu "65816"
.segment "CODE"
.org $F006
map_control_0ef006:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
