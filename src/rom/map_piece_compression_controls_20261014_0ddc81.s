.setcpu "65816"
.segment "CODE"
.org $DC81
map_control_0ddc81:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
