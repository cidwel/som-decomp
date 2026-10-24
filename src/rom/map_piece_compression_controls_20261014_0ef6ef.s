.setcpu "65816"
.segment "CODE"
.org $F6EF
map_control_0ef6ef:
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
