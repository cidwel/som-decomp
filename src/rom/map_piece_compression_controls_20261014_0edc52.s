.setcpu "65816"
.segment "CODE"
.org $DC52
map_control_0edc52:
    .byte $C4 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
