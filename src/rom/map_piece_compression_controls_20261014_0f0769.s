.setcpu "65816"
.segment "CODE"
.org $0769
map_control_0f0769:
    .byte $E6 ; previous-row copy count
    .byte $DF ; same-value copy count/distance
