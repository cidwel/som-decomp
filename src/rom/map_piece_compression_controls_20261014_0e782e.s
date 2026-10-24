.setcpu "65816"
.segment "CODE"
.org $782E
map_control_0e782e:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $AD ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
