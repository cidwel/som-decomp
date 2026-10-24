.setcpu "65816"
.segment "CODE"
.org $366C
map_control_0f366c:
    .byte $CB ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
