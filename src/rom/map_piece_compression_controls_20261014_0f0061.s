.setcpu "65816"
.segment "CODE"
.org $0061
map_control_0f0061:
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
