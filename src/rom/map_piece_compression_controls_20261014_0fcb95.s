.setcpu "65816"
.segment "CODE"
.org $CB95
map_control_0fcb95:
    .byte $CA ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E2 ; previous-row copy count
