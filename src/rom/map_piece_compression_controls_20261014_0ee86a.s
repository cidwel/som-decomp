.setcpu "65816"
.segment "CODE"
.org $E86A
map_control_0ee86a:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
