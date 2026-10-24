.setcpu "65816"
.segment "CODE"
.org $A42D
map_control_0ea42d:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $DC ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
