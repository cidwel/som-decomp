.setcpu "65816"
.segment "CODE"
.org $1ADD
map_control_0d1add:
    .byte $DC ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $A4 ; row-distance/count
