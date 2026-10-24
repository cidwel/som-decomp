.setcpu "65816"
.segment "CODE"
.org $E2B1
map_control_0ee2b1:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
