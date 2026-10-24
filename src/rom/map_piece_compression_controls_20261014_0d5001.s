.setcpu "65816"
.segment "CODE"
.org $5001
map_control_0d5001:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
