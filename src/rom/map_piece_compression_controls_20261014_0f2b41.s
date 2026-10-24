.setcpu "65816"
.segment "CODE"
.org $2B41
map_control_0f2b41:
    .byte $CD ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
