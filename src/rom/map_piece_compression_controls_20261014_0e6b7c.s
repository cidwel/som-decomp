.setcpu "65816"
.segment "CODE"
.org $6B7C
map_control_0e6b7c:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
