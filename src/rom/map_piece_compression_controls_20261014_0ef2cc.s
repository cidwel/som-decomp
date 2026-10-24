.setcpu "65816"
.segment "CODE"
.org $F2CC
map_control_0ef2cc:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
