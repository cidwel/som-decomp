.setcpu "65816"
.segment "CODE"
.org $5E5A
map_control_0c5e5a:
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
