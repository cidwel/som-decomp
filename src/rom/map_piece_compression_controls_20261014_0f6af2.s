.setcpu "65816"
.segment "CODE"
.org $6AF2
map_control_0f6af2:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
