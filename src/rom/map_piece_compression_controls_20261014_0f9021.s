.setcpu "65816"
.segment "CODE"
.org $9021
map_control_0f9021:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
    .byte $E1 ; previous-row copy count
