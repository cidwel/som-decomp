.setcpu "65816"
.segment "CODE"
.org $8CF1
map_control_0d8cf1:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E4 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
