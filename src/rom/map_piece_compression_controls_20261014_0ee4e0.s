.setcpu "65816"
.segment "CODE"
.org $E4E0
map_control_0ee4e0:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
