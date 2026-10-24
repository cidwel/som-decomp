.setcpu "65816"
.segment "CODE"
.org $DC99
map_control_0ddc99:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
