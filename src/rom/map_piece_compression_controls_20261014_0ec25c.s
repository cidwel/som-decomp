.setcpu "65816"
.segment "CODE"
.org $C25C
map_control_0ec25c:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
