.setcpu "65816"
.segment "CODE"
.org $4E2B
map_control_0d4e2b:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
