.setcpu "65816"
.segment "CODE"
.org $269E
map_control_0d269e:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
