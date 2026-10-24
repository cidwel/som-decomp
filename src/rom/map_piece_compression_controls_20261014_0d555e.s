.setcpu "65816"
.segment "CODE"
.org $555E
map_control_0d555e:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
