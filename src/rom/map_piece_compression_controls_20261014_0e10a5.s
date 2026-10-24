.setcpu "65816"
.segment "CODE"
.org $10A5
map_control_0e10a5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
