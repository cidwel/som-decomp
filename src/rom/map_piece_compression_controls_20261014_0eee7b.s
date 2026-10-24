.setcpu "65816"
.segment "CODE"
.org $EE7B
map_control_0eee7b:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
