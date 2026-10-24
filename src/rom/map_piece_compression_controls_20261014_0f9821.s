.setcpu "65816"
.segment "CODE"
.org $9821
map_control_0f9821:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
