.setcpu "65816"
.segment "CODE"
.org $4E6B
map_control_0f4e6b:
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
