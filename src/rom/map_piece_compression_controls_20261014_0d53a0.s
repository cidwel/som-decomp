.setcpu "65816"
.segment "CODE"
.org $53A0
map_control_0d53a0:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $4D ; row-distance/count
