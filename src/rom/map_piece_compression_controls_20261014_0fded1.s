.setcpu "65816"
.segment "CODE"
.org $DED1
map_control_0fded1:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
