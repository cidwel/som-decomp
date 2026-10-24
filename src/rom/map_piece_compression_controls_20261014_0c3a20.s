.setcpu "65816"
.segment "CODE"
.org $3A20
map_control_0c3a20:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
