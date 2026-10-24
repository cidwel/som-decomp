.setcpu "65816"
.segment "CODE"
.org $61AD
map_control_0e61ad:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
