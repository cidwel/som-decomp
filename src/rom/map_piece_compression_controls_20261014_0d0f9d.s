.setcpu "65816"
.segment "CODE"
.org $0F9D
map_control_0d0f9d:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
