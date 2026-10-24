.setcpu "65816"
.segment "CODE"
.org $4A4F
map_control_0f4a4f:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
