.setcpu "65816"
.segment "CODE"
.org $F721
map_control_0ef721:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
