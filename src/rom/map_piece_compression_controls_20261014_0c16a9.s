.setcpu "65816"
.segment "CODE"
.org $16A9
map_control_0c16a9:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
