.setcpu "65816"
.segment "CODE"
.org $5D52
map_control_0d5d52:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
