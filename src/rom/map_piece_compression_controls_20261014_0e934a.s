.setcpu "65816"
.segment "CODE"
.org $934A
map_control_0e934a:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
