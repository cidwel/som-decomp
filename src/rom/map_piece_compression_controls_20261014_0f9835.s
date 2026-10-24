.setcpu "65816"
.segment "CODE"
.org $9835
map_control_0f9835:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
