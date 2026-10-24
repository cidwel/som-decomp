.setcpu "65816"
.segment "CODE"
.org $F4CB
map_control_0ef4cb:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
