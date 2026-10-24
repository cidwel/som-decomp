.setcpu "65816"
.segment "CODE"
.org $DC74
map_control_0ddc74:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
