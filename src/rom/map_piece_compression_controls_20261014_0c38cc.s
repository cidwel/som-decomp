.setcpu "65816"
.segment "CODE"
.org $38CC
map_control_0c38cc:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
