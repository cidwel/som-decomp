.setcpu "65816"
.segment "CODE"
.org $E12A
map_control_0ee12a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
