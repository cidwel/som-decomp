.setcpu "65816"
.segment "CODE"
.org $274B
map_control_0e274b:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
