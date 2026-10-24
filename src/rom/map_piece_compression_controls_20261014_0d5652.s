.setcpu "65816"
.segment "CODE"
.org $5652
map_control_0d5652:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
