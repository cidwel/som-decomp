.setcpu "65816"
.segment "CODE"
.org $4A74
map_control_0d4a74:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
