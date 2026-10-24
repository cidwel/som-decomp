.setcpu "65816"
.segment "CODE"
.org $D44C
map_control_0ed44c:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
