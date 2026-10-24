.setcpu "65816"
.segment "CODE"
.org $B725
map_control_0db725:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E1 ; previous-row copy count
