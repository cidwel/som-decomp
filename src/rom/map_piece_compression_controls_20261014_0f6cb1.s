.setcpu "65816"
.segment "CODE"
.org $6CB1
map_control_0f6cb1:
    .byte $F2 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
