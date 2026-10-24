.setcpu "65816"
.segment "CODE"
.org $15CE
map_control_0f15ce:
    .byte $E3 ; previous-row copy count
