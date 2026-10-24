.setcpu "65816"
.segment "CODE"
.org $CED0
map_control_0dced0:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
