.setcpu "65816"
.segment "CODE"
.org $5DC1
map_control_0f5dc1:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $61 ; row-distance/count
