.setcpu "65816"
.segment "CODE"
.org $559D
map_control_0d559d:
    .byte $CA ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
