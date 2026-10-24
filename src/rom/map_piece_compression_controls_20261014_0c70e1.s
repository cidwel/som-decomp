.setcpu "65816"
.segment "CODE"
.org $70E1
map_control_0c70e1:
    .byte $DC ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
