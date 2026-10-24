.setcpu "65816"
.segment "CODE"
.org $F6F7
map_control_0ef6f7:
    .byte $E0 ; previous-row copy escape
    .byte $37 ; row-distance/count
