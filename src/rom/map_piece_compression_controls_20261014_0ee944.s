.setcpu "65816"
.segment "CODE"
.org $E944
map_control_0ee944:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
