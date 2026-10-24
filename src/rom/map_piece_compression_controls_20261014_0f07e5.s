.setcpu "65816"
.segment "CODE"
.org $07E5
map_control_0f07e5:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
