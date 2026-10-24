.setcpu "65816"
.segment "CODE"
.org $5E02
map_control_0d5e02:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
