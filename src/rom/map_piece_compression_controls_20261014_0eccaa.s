.setcpu "65816"
.segment "CODE"
.org $CCAA
map_control_0eccaa:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
