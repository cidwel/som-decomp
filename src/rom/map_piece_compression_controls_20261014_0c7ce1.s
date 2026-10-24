.setcpu "65816"
.segment "CODE"
.org $7CE1
map_control_0c7ce1:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
