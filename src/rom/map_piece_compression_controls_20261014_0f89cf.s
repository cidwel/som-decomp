.setcpu "65816"
.segment "CODE"
.org $89CF
map_control_0f89cf:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
