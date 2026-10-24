.setcpu "65816"
.segment "CODE"
.org $3863
map_control_0e3863:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C9 ; same-value copy count/distance
