.setcpu "65816"
.segment "CODE"
.org $4AD2
map_control_0f4ad2:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
