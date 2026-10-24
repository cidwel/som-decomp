.setcpu "65816"
.segment "CODE"
.org $2737
map_control_0c2737:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
