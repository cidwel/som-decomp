.setcpu "65816"
.segment "CODE"
.org $73B7
map_control_0c73b7:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
