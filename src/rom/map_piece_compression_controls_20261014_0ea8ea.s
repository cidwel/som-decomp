.setcpu "65816"
.segment "CODE"
.org $A8EA
map_control_0ea8ea:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
