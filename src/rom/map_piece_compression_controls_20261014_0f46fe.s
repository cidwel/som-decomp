.setcpu "65816"
.segment "CODE"
.org $46FE
map_control_0f46fe:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
