.setcpu "65816"
.segment "CODE"
.org $112A
map_control_0c112a:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
