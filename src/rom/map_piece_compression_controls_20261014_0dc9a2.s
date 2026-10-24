.setcpu "65816"
.segment "CODE"
.org $C9A2
map_control_0dc9a2:
    .byte $D1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
