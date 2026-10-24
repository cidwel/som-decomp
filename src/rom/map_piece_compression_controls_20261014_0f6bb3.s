.setcpu "65816"
.segment "CODE"
.org $6BB3
map_control_0f6bb3:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
