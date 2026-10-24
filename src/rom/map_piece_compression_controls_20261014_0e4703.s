.setcpu "65816"
.segment "CODE"
.org $4703
map_control_0e4703:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
