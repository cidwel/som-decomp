.setcpu "65816"
.segment "CODE"
.org $4907
map_control_0f4907:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
