.setcpu "65816"
.segment "CODE"
.org $CB0F
map_control_0ecb0f:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
