.setcpu "65816"
.segment "CODE"
.org $4F23
map_control_0f4f23:
    .byte $CE ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
