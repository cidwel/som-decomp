.setcpu "65816"
.segment "CODE"
.org $F2E0
map_control_0df2e0:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
