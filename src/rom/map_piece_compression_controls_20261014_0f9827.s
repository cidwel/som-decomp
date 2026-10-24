.setcpu "65816"
.segment "CODE"
.org $9827
map_control_0f9827:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
