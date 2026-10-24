.setcpu "65816"
.segment "CODE"
.org $6089
map_control_0f6089:
    .byte $E4 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
