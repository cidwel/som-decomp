.setcpu "65816"
.segment "CODE"
.org $8D60
map_control_0f8d60:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
