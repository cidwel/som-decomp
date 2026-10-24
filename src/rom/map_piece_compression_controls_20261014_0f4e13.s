.setcpu "65816"
.segment "CODE"
.org $4E13
map_control_0f4e13:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
