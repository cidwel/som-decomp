.setcpu "65816"
.segment "CODE"
.org $E8CF
map_control_0de8cf:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
