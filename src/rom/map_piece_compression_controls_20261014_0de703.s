.setcpu "65816"
.segment "CODE"
.org $E703
map_control_0de703:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
