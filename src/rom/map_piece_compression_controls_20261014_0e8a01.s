.setcpu "65816"
.segment "CODE"
.org $8A01
map_control_0e8a01:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
