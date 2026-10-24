.setcpu "65816"
.segment "CODE"
.org $DC7B
map_control_0ddc7b:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
