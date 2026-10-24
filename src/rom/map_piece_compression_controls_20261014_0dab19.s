.setcpu "65816"
.segment "CODE"
.org $AB19
map_control_0dab19:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
