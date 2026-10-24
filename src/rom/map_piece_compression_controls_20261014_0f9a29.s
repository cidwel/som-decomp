.setcpu "65816"
.segment "CODE"
.org $9A29
map_control_0f9a29:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
