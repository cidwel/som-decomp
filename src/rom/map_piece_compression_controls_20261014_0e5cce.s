.setcpu "65816"
.segment "CODE"
.org $5CCE
map_control_0e5cce:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
