.setcpu "65816"
.segment "CODE"
.org $0059
map_control_0f0059:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
