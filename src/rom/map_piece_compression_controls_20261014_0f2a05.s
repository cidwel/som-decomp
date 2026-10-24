.setcpu "65816"
.segment "CODE"
.org $2A05
map_control_0f2a05:
    .byte $E1 ; previous-row copy count
    .byte $DC ; same-value copy count/distance
