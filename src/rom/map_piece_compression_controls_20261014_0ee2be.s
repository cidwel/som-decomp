.setcpu "65816"
.segment "CODE"
.org $E2BE
map_control_0ee2be:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
