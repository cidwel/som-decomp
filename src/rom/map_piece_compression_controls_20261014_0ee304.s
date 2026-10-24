.setcpu "65816"
.segment "CODE"
.org $E304
map_control_0ee304:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $E3 ; previous-row copy count
