.setcpu "65816"
.segment "CODE"
.org $9F12
map_control_0f9f12:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $F1 ; progressive-copy count
    .byte $D2 ; same-value copy count/distance
