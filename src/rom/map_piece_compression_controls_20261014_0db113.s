.setcpu "65816"
.segment "CODE"
.org $B113
map_control_0db113:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
