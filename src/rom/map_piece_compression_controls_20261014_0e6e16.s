.setcpu "65816"
.segment "CODE"
.org $6E16
map_control_0e6e16:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
