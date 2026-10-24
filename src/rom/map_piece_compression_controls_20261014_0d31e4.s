.setcpu "65816"
.segment "CODE"
.org $31E4
map_control_0d31e4:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
