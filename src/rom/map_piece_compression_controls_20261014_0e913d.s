.setcpu "65816"
.segment "CODE"
.org $913D
map_control_0e913d:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
