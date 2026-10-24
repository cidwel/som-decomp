.setcpu "65816"
.segment "CODE"
.org $31E1
map_control_0f31e1:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
