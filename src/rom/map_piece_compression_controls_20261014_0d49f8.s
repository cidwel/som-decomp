.setcpu "65816"
.segment "CODE"
.org $49F8
map_control_0d49f8:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
