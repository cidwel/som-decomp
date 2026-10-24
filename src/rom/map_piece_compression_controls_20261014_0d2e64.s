.setcpu "65816"
.segment "CODE"
.org $2E64
map_control_0d2e64:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
