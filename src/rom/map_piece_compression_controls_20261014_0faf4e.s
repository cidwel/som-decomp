.setcpu "65816"
.segment "CODE"
.org $AF4E
map_control_0faf4e:
    .byte $DC ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
