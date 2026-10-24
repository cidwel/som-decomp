.setcpu "65816"
.segment "CODE"
.org $13B6
map_control_0e13b6:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
