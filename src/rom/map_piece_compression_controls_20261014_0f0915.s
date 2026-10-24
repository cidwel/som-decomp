.setcpu "65816"
.segment "CODE"
.org $0915
map_control_0f0915:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
