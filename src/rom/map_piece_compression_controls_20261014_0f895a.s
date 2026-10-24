.setcpu "65816"
.segment "CODE"
.org $895A
map_control_0f895a:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
