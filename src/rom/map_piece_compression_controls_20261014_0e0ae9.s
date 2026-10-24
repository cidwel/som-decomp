.setcpu "65816"
.segment "CODE"
.org $0AE9
map_control_0e0ae9:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
