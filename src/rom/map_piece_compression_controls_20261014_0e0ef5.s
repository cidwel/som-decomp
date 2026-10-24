.setcpu "65816"
.segment "CODE"
.org $0EF5
map_control_0e0ef5:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
