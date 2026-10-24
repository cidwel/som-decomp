.setcpu "65816"
.segment "CODE"
.org $669E
map_control_0d669e:
    .byte $E0 ; previous-row copy escape
    .byte $D9 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
