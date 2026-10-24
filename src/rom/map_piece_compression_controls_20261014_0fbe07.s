.setcpu "65816"
.segment "CODE"
.org $BE07
map_control_0fbe07:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
