.setcpu "65816"
.segment "CODE"
.org $74AF
map_control_0e74af:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
