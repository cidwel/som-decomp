.setcpu "65816"
.segment "CODE"
.org $31EB
map_control_0c31eb:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
