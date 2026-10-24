.setcpu "65816"
.segment "CODE"
.org $CBB5
map_control_0ecbb5:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
