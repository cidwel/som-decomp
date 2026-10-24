.setcpu "65816"
.segment "CODE"
.org $0EED
map_control_0e0eed:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
