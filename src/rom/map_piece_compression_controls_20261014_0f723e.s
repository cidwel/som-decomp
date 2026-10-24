.setcpu "65816"
.segment "CODE"
.org $723E
map_control_0f723e:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
