.setcpu "65816"
.segment "CODE"
.org $FFD6
map_control_0dffd6:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
