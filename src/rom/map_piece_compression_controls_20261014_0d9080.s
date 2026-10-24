.setcpu "65816"
.segment "CODE"
.org $9080
map_control_0d9080:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
