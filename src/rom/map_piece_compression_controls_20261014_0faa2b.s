.setcpu "65816"
.segment "CODE"
.org $AA2B
map_control_0faa2b:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
