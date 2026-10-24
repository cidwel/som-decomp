.setcpu "65816"
.segment "CODE"
.org $6559
map_control_0f6559:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
