.setcpu "65816"
.segment "CODE"
.org $7E00
map_control_0e7e00:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
