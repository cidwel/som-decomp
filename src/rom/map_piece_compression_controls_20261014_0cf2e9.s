.setcpu "65816"
.segment "CODE"
.org $F2E9
map_control_0cf2e9:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
