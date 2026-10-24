.setcpu "65816"
.segment "CODE"
.org $74E5
map_control_0c74e5:
    .byte $E5 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
