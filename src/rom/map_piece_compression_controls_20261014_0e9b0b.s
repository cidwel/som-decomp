.setcpu "65816"
.segment "CODE"
.org $9B0B
map_control_0e9b0b:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
