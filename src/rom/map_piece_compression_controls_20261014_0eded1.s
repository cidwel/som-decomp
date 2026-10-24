.setcpu "65816"
.segment "CODE"
.org $DED1
map_control_0eded1:
    .byte $E3 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
