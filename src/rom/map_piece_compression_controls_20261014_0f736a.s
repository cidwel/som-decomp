.setcpu "65816"
.segment "CODE"
.org $736A
map_control_0f736a:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $AC ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
