.setcpu "65816"
.segment "CODE"
.org $433B
map_control_0e433b:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
