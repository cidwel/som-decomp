.setcpu "65816"
.segment "CODE"
.org $F86C
map_control_0df86c:
    .byte $F5 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
