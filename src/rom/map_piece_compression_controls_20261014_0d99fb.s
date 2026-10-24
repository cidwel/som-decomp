.setcpu "65816"
.segment "CODE"
.org $99FB
map_control_0d99fb:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
