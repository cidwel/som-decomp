.setcpu "65816"
.segment "CODE"
.org $5EBE
map_control_0d5ebe:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
