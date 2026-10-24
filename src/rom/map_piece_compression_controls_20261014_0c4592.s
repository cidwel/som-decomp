.setcpu "65816"
.segment "CODE"
.org $4592
map_control_0c4592:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
