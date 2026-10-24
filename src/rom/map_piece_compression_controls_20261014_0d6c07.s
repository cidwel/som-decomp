.setcpu "65816"
.segment "CODE"
.org $6C07
map_control_0d6c07:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
