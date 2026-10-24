.setcpu "65816"
.segment "CODE"
.org $E969
map_control_0ee969:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
