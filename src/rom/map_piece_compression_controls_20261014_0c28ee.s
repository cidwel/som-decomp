.setcpu "65816"
.segment "CODE"
.org $28EE
map_control_0c28ee:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
    .byte $C2 ; same-value copy count/distance
