.setcpu "65816"
.segment "CODE"
.org $6411
map_control_0e6411:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
