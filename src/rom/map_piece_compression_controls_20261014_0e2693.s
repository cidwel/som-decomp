.setcpu "65816"
.segment "CODE"
.org $2693
map_control_0e2693:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
