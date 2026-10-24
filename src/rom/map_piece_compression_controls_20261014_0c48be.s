.setcpu "65816"
.segment "CODE"
.org $48BE
map_control_0c48be:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
