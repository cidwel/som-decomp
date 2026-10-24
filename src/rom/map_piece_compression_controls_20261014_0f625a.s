.setcpu "65816"
.segment "CODE"
.org $625A
map_control_0f625a:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
    .byte $CC ; same-value copy count/distance
