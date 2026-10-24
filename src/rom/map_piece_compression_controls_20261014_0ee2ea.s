.setcpu "65816"
.segment "CODE"
.org $E2EA
map_control_0ee2ea:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
