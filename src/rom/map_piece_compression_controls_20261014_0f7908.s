.setcpu "65816"
.segment "CODE"
.org $7908
map_control_0f7908:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
