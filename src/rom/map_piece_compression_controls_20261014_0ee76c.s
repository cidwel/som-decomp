.setcpu "65816"
.segment "CODE"
.org $E76C
map_control_0ee76c:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
