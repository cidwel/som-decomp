.setcpu "65816"
.segment "CODE"
.org $CB7D
map_control_0fcb7d:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
