.setcpu "65816"
.segment "CODE"
.org $5708
map_control_0d5708:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
