.setcpu "65816"
.segment "CODE"
.org $7E9B
map_control_0d7e9b:
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
