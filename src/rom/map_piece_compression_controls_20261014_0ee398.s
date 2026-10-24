.setcpu "65816"
.segment "CODE"
.org $E398
map_control_0ee398:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
