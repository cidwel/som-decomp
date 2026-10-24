.setcpu "65816"
.segment "CODE"
.org $E2B5
map_control_0ee2b5:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
