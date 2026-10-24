.setcpu "65816"
.segment "CODE"
.org $4F4D
map_control_0f4f4d:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
