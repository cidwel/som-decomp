.setcpu "65816"
.segment "CODE"
.org $B02A
map_control_0db02a:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
