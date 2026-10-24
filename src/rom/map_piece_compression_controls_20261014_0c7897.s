.setcpu "65816"
.segment "CODE"
.org $7897
map_control_0c7897:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
