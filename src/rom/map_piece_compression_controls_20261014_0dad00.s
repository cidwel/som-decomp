.setcpu "65816"
.segment "CODE"
.org $AD00
map_control_0dad00:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $FF ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
