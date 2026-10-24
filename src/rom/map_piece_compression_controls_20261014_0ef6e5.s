.setcpu "65816"
.segment "CODE"
.org $F6E5
map_control_0ef6e5:
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
