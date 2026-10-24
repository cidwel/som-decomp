.setcpu "65816"
.segment "CODE"
.org $7B48
map_control_0d7b48:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
