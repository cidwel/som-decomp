.setcpu "65816"
.segment "CODE"
.org $F7AF
map_control_0ef7af:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
