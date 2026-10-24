.setcpu "65816"
.segment "CODE"
.org $867B
map_control_0f867b:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
