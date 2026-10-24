.setcpu "65816"
.segment "CODE"
.org $31FE
map_control_0f31fe:
    .byte $E0 ; previous-row copy escape
    .byte $8E ; row-distance/count
