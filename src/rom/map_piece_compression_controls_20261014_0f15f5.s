.setcpu "65816"
.segment "CODE"
.org $15F5
map_control_0f15f5:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
