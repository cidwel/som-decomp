.setcpu "65816"
.segment "CODE"
.org $9B51
map_control_0f9b51:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
