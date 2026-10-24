.setcpu "65816"
.segment "CODE"
.org $0F05
map_control_0d0f05:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
