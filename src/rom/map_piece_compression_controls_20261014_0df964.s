.setcpu "65816"
.segment "CODE"
.org $F964
map_control_0df964:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
