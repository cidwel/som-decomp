.setcpu "65816"
.segment "CODE"
.org $46D2
map_control_0f46d2:
    .byte $E0 ; previous-row copy escape
    .byte $57 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
