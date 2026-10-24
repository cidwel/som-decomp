.setcpu "65816"
.segment "CODE"
.org $724C
map_control_0c724c:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
