.setcpu "65816"
.segment "CODE"
.org $F747
map_control_0ef747:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
