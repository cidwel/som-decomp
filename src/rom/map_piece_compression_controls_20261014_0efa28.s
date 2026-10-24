.setcpu "65816"
.segment "CODE"
.org $FA28
map_control_0efa28:
    .byte $E0 ; previous-row copy escape
    .byte $AE ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8B ; row-distance/count
